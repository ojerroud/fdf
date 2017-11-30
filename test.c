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

void			draw(t_fdf ptr, t_coord pts, t_data *getadrr)
{
	getadrr->data = (int *)mlx_get_data_addr(ptr.img, &getadrr->bpp,
		&getadrr->sizeline, &getadrr->endian);
	while (pts.y < 100)
	{
		pts.x = 50;
		while (pts.x < 100)
		{
			getadrr->data[WIN_WIDTH * pts.y + pts.x] = 0xFFFFFF;
			pts.x++;
		}
		pts.y++;
	}
}

int				esc_event(int keycode, void *param)
{
	if (keycode == 53)
		exit(0);
	return ((int)param);
}

int				main(void)
{
	t_fdf			ptr;
	t_coord			pts;
	t_data			getadrr;

	ptr.mlx = mlx_init();
	ptr.win = mlx_new_window(ptr.mlx, WIN_WIDTH, WIN_HEIGHT, "fdf");
	if (mlx_key_hook(ptr.win, esc_event, 0) == 1)
		return (0);
	ptr.img = mlx_new_image(ptr.mlx, WIN_WIDTH, WIN_HEIGHT);
	pts.y = 50;
	draw(ptr, pts, &getadrr);
	mlx_put_image_to_window(ptr.mlx, ptr.win, ptr.img, 0, 0);
	mlx_loop(ptr.mlx);
	return (0);
}
