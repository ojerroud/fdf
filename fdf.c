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

/*
**	int		click_event(int button, int x, int y, void *param)
**	{
**	printf("button %d. x = %d et y = %d\n", button, x, y);
**	return ((int)param);
**	}
*/

void	draw(t_fdf ptr)
{
	int		x;
	int		y;

	y = EDGE_DIST;
	while (y <= (WIN_HEIGHT - EDGE_DIST))
	{
		x = EDGE_DIST;
		while (x <= (WIN_WIDTH - EDGE_DIST))
		{
			mlx_pixel_put(ptr.mlx, ptr.win, x, y, 0X00FFFFFF);
			x++;
		}
		y += POINT_DIST;
	}
	y = EDGE_DIST;
	while (y <= (WIN_HEIGHT - EDGE_DIST))
	{
		x = EDGE_DIST;
		while (x <= (WIN_WIDTH - EDGE_DIST))
		{
			mlx_pixel_put(ptr.mlx, ptr.win, x, y, 0X00FFFFFF);
			x += POINT_DIST;
		}
		y++;
	}
}

int		main(int ac, char **av)
{
	t_fdf	ptr;
	char	*line;
	int		i;
	int		fd;
	int		ret;

	if (ac != 2)
		return (1);
	i = 0;
	fd = open(av[1], O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
		i++;
	close(fd);
	fd = open(av[1], O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		i++;
	}
	close(fd);
	if (ret == -1)
	{
		printf("error\n");
		exit(1);
	}
	printf("%d\n", i);
/*
**	ptr.mlx = mlx_init();
**	ptr.win = mlx_new_window(ptr.mlx, WIN_WIDTH, WIN_HEIGHT, "fdf");
**	if (mlx_key_hook(ptr.win, esc_event, 0) == 1)
**		return (0);
**	mlx_mouse_hook(ptr.win, click_event, 0);
*/
	draw(ptr);
	mlx_loop(ptr.mlx);
	return (0);
}
