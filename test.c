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

int		esc_event(int keycode, void *param)
{
	if (keycode == 53)
		exit(1);
	return ((int)param);
}

void	ft_lstprint_fdf(t_coord *list)
{
	t_coord	*tmp;

	tmp = list;
	while (tmp)
	{
		ft_putnbr((size_t)tmp->x);
		ft_putchar(' ');
		ft_putnbr((size_t)tmp->y);
		ft_putchar('\n');
		tmp = tmp->next;
	}
}

void	ft_lstadd_fdf(t_coord **alst, t_coord *new)
{
	new->next = *alst;
	*alst = new;
}


t_coord	*ft_lstnew_fdf(size_t x, size_t y)
{
	t_coord	*tmp;

	if (!(tmp = (t_coord *)malloc(sizeof(t_coord))))
		return (NULL);
	tmp->x = x;
	tmp->y = y;
	tmp->next = NULL;
	return (tmp);
}

void	draw(t_fdf ptr, t_file_param file)
{
	t_coord	*fdf;
	t_coord	*curr;
	float		x;
	float		y;
	float		h;
	float		w;

	fdf = NULL;
	h = ((float)WIN_HEIGHT - ((float)EDGE_DIST * 2)) / ((float)file.height - 1);
	w = ((float)WIN_WIDTH - ((float)EDGE_DIST * 2)) / ((float)file.width - 1);
	y = EDGE_DIST;
	while (y <= (WIN_HEIGHT - EDGE_DIST))
	{
		x = EDGE_DIST;
		while (x <= (WIN_WIDTH - EDGE_DIST))
		{
			mlx_pixel_put(ptr.mlx, ptr.win, x, y, 0X00FFFFFF);
			curr = ft_lstnew_fdf(x, y);
			ft_lstadd_fdf(&fdf, curr);
			x += w;
		}
		y += h;
	}
	ft_lstprint_fdf(fdf);
}

int		main(int ac, char **av)
{
	t_file_param	file;
	t_fdf			ptr;
	int				**tab;
	char			**tmp;
	char			*line;
	int				fd;
	int				ret;
	size_t			i;
	size_t			y;

	if (ac != 2)
		return (1);
	file.height = 0;
	fd = open(av[1], O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		ft_strdel(&line);
		file.height++;
	}
	if (ret == -1)
		return (-1);
	close(fd);
	tab = (int **)malloc(sizeof(int*) * file.height);
	y = 0;
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		tmp = ft_strsplit(line, ' ');
		ft_strdel(&line);
		i = 0;
		while (tmp[i])
			i++;
		file.width = i;
		tab[y] = (int *)malloc(sizeof(int) * i);
		i = -1;
		while (tmp[++i])
		{
			tab[y][i] = ft_atoi(tmp[i]);
			ft_strdel(&tmp[i]);
		}
		y++;
		free(tmp);
	}
	ptr.mlx = mlx_init();
	ptr.win = mlx_new_window(ptr.mlx, WIN_WIDTH, WIN_HEIGHT, "fdf");
	if (mlx_key_hook(ptr.win, esc_event, 0) == 1)
		return (0);
	draw(ptr, file);
	mlx_loop(ptr.mlx);
/*
y = 0;
while (file.height > y)
{
	i = 0;
	while (file.width > i)
	{
		printf("%d ", tab[y][i]);
		i++;
	}
	printf("\n");
	y++;
}
*/
/*
	fd = open(av[1], O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
		i++;
	close(fd);
*/
	return (0);
}
