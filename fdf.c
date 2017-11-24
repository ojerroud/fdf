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

void			t2Dt3D(t_coord **tab, t_file_param file)
{
	int	i;
	int	j;
	int	tile_height;
	int	tile_width;
	int	x_out;
	int	y_out;

	x_out = 0;
	y_out = 0;
	if ((tab[0][0]).x > 0 && (tab[0][1]).x > 0 && (tab[1][0]).x > 0)
	{
		tile_height = tab[1][0].y - tab[0][0].y;
		tile_width = tab[0][1].x - tab[0][0].x;
	}
	i = 0;
	while (i < file.height)
	{
		j = 0;
		while (j < file.width)
		{
			tab[i][j].x = (j - i) * (tile_width / 2) + (WIN_WIDTH / 2.5);
			tab[i][j].y = (i + j) * (tile_height / 8) + (WIN_HEIGHT / 4);
			if (tab[i][j].x < x_out)
				x_out = tab[i][j].x;
			if (tab[i][j].y < y_out)
				y_out = tab[i][j].y;
			printf("%d|%d\n", tab[i][j].x, tab[i][j].y);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < file.height)
	{
		j = 0;
		while (j < file.width)
		{
			if (tab[i][j].z != 0)
				tab[i][j].y -= (tab[i][j].z * 2);
			tab[i][j].x -= x_out;
			tab[i][j].y -= y_out;
			j++;
		}
		i++;
	}
}

void 			link_dots(t_fdf ptr, t_coord strct1, t_coord strct2, int sommet)
{
	int	dx;
	int	dy;
	int	i;
	int	xinc;
	int	yinc;
	int	cumul;
	int	x;
	int	y;

	sommet = 80 * sommet / 100;
	x = strct1.x;
	y = strct1.y;
	dx = strct2.x - strct1.x;
	dy = strct2.y - strct1.y;
	xinc = (dx > 0) ? 1 : -1;
	yinc = (dy > 0) ? 1 : -1;
	dx = abs(dx);
	dy = abs(dy);
	if (strct1.z >= sommet && strct2.z >= sommet)
	{
		mlx_pixel_put(ptr.mlx, ptr.win, x, y, 0X00FFFFFF);
		if (dx > dy)
		{
			cumul = dx / 2;
			for ( i = 1; i <= dx; i++ )
			{
				x += xinc;
				cumul += dy;
				if ( cumul >= dx )
				{
					cumul -= dx;
					y += yinc;
				}
				mlx_pixel_put(ptr.mlx, ptr.win, x, y, 0X00FFFFFF);
			}
		}
		else
		{
			cumul = dy / 2;
			for ( i = 1; i <= dy; i++ )
			{
				y += yinc;
				cumul += dx;
				if ( cumul >= dy )
				{
					cumul -= dy;
					x += xinc;
				}
				mlx_pixel_put(ptr.mlx, ptr.win, x, y, 0X00FFFFFF);
			}
		}
	}
	else if (!strct1.z && !strct2.z)
	{
		mlx_pixel_put(ptr.mlx, ptr.win, x, y, 0X00008000);
		if (dx > dy)
		{
			cumul = dx / 2;
			for ( i = 1; i <= dx; i++ )
			{
				x += xinc;
				cumul += dy;
				if ( cumul >= dx )
				{
					cumul -= dx;
					y += yinc;
				}
				mlx_pixel_put(ptr.mlx, ptr.win, x, y, 0X00008000);
			}
		}
		else
		{
			cumul = dy / 2;
			for ( i = 1; i <= dy; i++ )
			{
				y += yinc;
				cumul += dx;
				if ( cumul >= dy )
				{
					cumul -= dy;
					x += xinc;
				}
				mlx_pixel_put(ptr.mlx, ptr.win, x, y, 0X00008000);
			}
		}
	}
	else
	{
		mlx_pixel_put(ptr.mlx, ptr.win, x, y, 0X00582900);
		if (dx > dy)
		{
			cumul = dx / 2;
			for ( i = 1; i <= dx; i++ )
			{
				x += xinc;
				cumul += dy;
				if ( cumul >= dx )
				{
					cumul -= dx;
					y += yinc;
				}
				mlx_pixel_put(ptr.mlx, ptr.win, x, y, 0X00582900);
			}
		}
		else
		{
			cumul = dy / 2;
			for ( i = 1; i <= dy; i++ )
			{
				y += yinc;
				cumul += dx;
				if ( cumul >= dy )
				{
					cumul -= dy;
					x += xinc;
				}
				mlx_pixel_put(ptr.mlx, ptr.win, x, y, 0X00582900);
			}
		}
	}
}

void			print_tab(t_fdf ptr, t_file_param file, t_coord **tab)
{
	int	i;
	int	j;
	int	sommet;

	i = -1;
	sommet = 0;
	while (file.height > ++i)
	{
		j = -1;
		while (file.width > ++j)
			if ((tab[i][j].z) > sommet)
				sommet = tab[i][j].z;
	}
	i = -1;
	while (file.height > ++i)
	{
		j = -1;
		while (file.width - 1 > ++j)
			link_dots(ptr, tab[i][j], tab[i][j + 1], sommet);
	}
	i = -1;
	while (file.height - 1 > ++i)
	{
		j = -1;
		while (file.width > ++j)
			link_dots(ptr, tab[i][j], tab[i + 1][j], sommet);
	}
}

int				esc_event(int keycode, void *param)
{
	if (keycode == 53)
		exit(1);
	return ((int)param);
}

void			sav_coord(t_file_param file, t_coord **tab)
{
	float	x_val;
	float	y_val;
	float	h;
	float	w;
	int		i[2];

	h = ((float)WIN_HEIGHT - ((float)EDGE_DIST * 2)) / (file.height - 1);
	w = ((float)WIN_WIDTH - ((float)EDGE_DIST * 2)) / (file.width - 1);
	y_val = EDGE_DIST;
	i[1] = 0;
	while (y_val <= (WIN_HEIGHT - EDGE_DIST))
	{
		x_val = EDGE_DIST;
		i[0] = 0;
		while (x_val <= (WIN_WIDTH - EDGE_DIST))
		{
			tab[i[1]][i[0]].x = x_val;
			tab[i[1]][i[0]].y = y_val;
			x_val += w;
			i[0]++;
		}
		y_val += h;
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
	sav_coord(file, tab);
	ptr.mlx = mlx_init();
	ptr.win = mlx_new_window(ptr.mlx, WIN_WIDTH, WIN_HEIGHT, "fdf");
	if (mlx_key_hook(ptr.win, esc_event, 0) == 1)
		return (0);
	t2Dt3D(tab, file);
	print_tab(ptr, file, tab);
	mlx_loop(ptr.mlx);
	return (0);
}
