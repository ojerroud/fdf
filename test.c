/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 16:52:22 by ojerroud          #+#    #+#             */
/*   Updated: 2017/09/26 17:31:20 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void			link_dots(t_fdf ptr, t_coord strct1, t_coord strct2)
{
	int	dx;
	int	dy;
	int	cumul;
	int	x;
	int	y;

	y = strct1.y;
	dx = strct2.x - strct1.x;
	dy = strct2.y - strct1.y;
	if (strct2.x > strct1.x && strct2.y >= strct1.y && (strct2.x - strct1.x) >= (strct2.y - strct1.y))
	{
		mlx_pixel_put(ptr.mlx, ptr.win, strct1.x, y, 0X00FFFFFF);
		cumul = dx / 2;
		x = strct1.x + 1;
		while (x <= strct2.x)
		{
			cumul += dy;
			if (cumul >= dx)
			{
				cumul -= dx;
				y += 1;
			}
			mlx_pixel_put(ptr.mlx, ptr.win, x, y, 0X00FFFFFF);
			x++;
		}
	}
	else
	{
		x = strct1.x;
		mlx_pixel_put(ptr.mlx, ptr.win, strct1.x, y, 0X00FFFFFF);
		cumul = dy / 2;
		y = strct1.y + 1;
		while (y <= strct2.y)
		{
			cumul += dx;
			if (cumul >= dy)
			{
				cumul -= dy;
				x += 1;
			}
			mlx_pixel_put(ptr.mlx, ptr.win, x, y, 0X00FFFFFF);
			y++;
		}
	}
}

void			print_tab(t_fdf ptr, t_file_param file, t_coord **tab)
{
	int	i;
	int	j;

	i = -1;
	while (file.height > ++i)
	{
		j = -1;
		while (file.width - 1 > ++j)
			link_dots(ptr, tab[i][j], tab[i][j + 1]);
	}
	i = -1;
	while (file.height - 1 > ++i)
	{
		j = -1;
		while (file.width > ++j)
			link_dots(ptr, tab[i][j], tab[i + 1][j]);
	}
	/* a ajouter verticale*/
}

int				esc_event(int keycode, void *param)
{
	if (keycode == 53)
		exit(1);
	return ((int)param);
}

void			sav_coord(t_file_param file, t_coord **tab)
{
	float	x;
	float	y;
	float	h;
	float	w;
	int		i[2];

	h = ((float)WIN_HEIGHT - ((float)EDGE_DIST * 2)) / (file.height - 1);
	w = ((float)WIN_WIDTH - ((float)EDGE_DIST * 2)) / (file.width - 1);
	y = EDGE_DIST;
	i[1] = 0;
	while (y <= (WIN_HEIGHT - EDGE_DIST))
	{
		x = EDGE_DIST;
		i[0] = 0;
		while (x <= (WIN_WIDTH - EDGE_DIST))
		{
			//mlx_pixel_put(ptr.mlx, ptr.win, x, y, 0X00FFFFFF);
			tab[i[1]][i[0]].x = x;
			tab[i[1]][i[0]].y = y;
			x += w;
			i[0]++;
		}
		y += h;
		i[1]++;
	}
}

t_file_param	compt_line(char *input)
{
	int				ret;
	int				fd;
	char			*line;
	t_file_param	file;

	fd = open(input, O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		ft_strdel(&line);
		file.height++;
	}
	if (ret == -1)
	{
		file.height = -1;
		return (file);
	}
	close(fd);
	return (file);
}

t_coord			**compt_colomn(char *input, t_file_param *file, t_coord **tab)
{
	char	**tmp;
	char	*line;
	int		fd;
	int		i[2];

	i[1] = -1;
	fd = open(input, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		tmp = ft_strsplit(line, ' ');
		ft_strdel(&line);
		i[0] = 0;
		while (tmp[i[0]])
			i[0]++;
		file->width = i[0];
		tab[++i[1]] = (t_coord *)malloc(sizeof(t_coord) * i[0]);
		i[0] = -1;
		while (tmp[++i[0]])
		{
			tab[i[1]][i[0]].z = ft_atoi(tmp[i[0]]);
			ft_strdel(&tmp[i[0]]);
		}
		free(tmp);
	}
	return (tab);
}

int				main(int ac, char **av)
{
	t_file_param	file;
	t_fdf			ptr;
	t_coord			**tab;

	if (ac != 2)
		return (-1);
	file = compt_line(av[1]);
	if (file.height == -1)
		return (-1);
	tab = (t_coord **)malloc(sizeof(t_coord*) * file.height);
	tab = compt_colomn(av[1], &file, tab);
	ptr.mlx = mlx_init();
	ptr.win = mlx_new_window(ptr.mlx, WIN_WIDTH, WIN_HEIGHT, "fdf");
	if (mlx_key_hook(ptr.win, esc_event, 0) == 1)
		return (0);
	sav_coord(file, tab);
	print_tab(ptr, file, tab);
	mlx_loop(ptr.mlx);
	return (0);
}
