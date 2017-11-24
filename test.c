/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 14:08:17 by ojerroud          #+#    #+#             */
/*   Updated: 2017/11/24 14:08:19 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

int		esc_event(int keycode, void *param)
{
	if (keycode == 53)
		exit(1);
	return ((int)param);
}

int		coord(int button, int x, int y, void *param)
{
	printf("%d %d %d\n", button, x, y);
	return ((int)param);
}

void	link_dots(t_fdf ptr, int ax, int ay, int bx, int by)
{
	int	dx;
	int	dy;
	int	cumul;
	int	x;
	int	y;

	y = ay;
	dx = bx - ax;
	dy = by - ay;
	if (bx > ax && by >= ay && (bx - ax) >= (by - ay))
	{
		mlx_pixel_put(ptr.mlx, ptr.win, ax, y, 0X00FFFFFF);
		cumul = dx / 2;
		x = ax + 1;
		while (x <= bx)
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
		x = ax;
		mlx_pixel_put(ptr.mlx, ptr.win, ax, y, 0X00FFFFFF);
		cumul = dy / 2;
		y = ay + 1;
		while (y <= by)
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

void ligne(t_fdf ptr, int xi, int yi, int xf, int yf)
{
	int	dx;
	int	dy;
	int	i;
	int	xinc;
	int	yinc;
	int	cumul;
	int	x;
	int	y;

	x = xi;
	y = yi;
	dx = xf - xi;
	dy = yf - yi;
	xinc = (dx > 0) ? 1 : -1;
	yinc = (dy > 0) ? 1 : -1;
	dx = abs(dx);
	dy = abs(dy);
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

int		main(int ac, char **av)
{
	t_fdf	ptr;

	if (ac != 5)
		return (0);
	ptr.mlx = mlx_init();
	ptr.win = mlx_new_window(ptr.mlx, WIN_WIDTH, WIN_HEIGHT, "fdf");
	mlx_key_hook(ptr.win, esc_event, 0);
	mlx_mouse_hook(ptr.win, coord, 0);
	ligne(ptr, ft_atoi(av[1]), ft_atoi(av[2]), ft_atoi(av[3]), ft_atoi(av[4]));
	//link_dots(ptr, ft_atoi(av[1]), ft_atoi(av[2]), ft_atoi(av[3]), ft_atoi(av[4]));
	mlx_loop(ptr.mlx);
	return (0);
}