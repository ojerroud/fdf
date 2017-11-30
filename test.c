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
	unsigned int	color;
	/*unsigned int	r;
	unsigned int	g;
	unsigned int	b;*/

	color = mlx_get_color_value(ptr.mlx, 0x00FFFFFF);
	getadrr->data = mlx_get_data_addr(ptr.img, &getadrr->bpp, &getadrr->sizeline, &getadrr->endian);
	printf("bpp = %d (/8 = %d), longueur ligne = %d et endian = %d\n", getadrr->bpp, getadrr->bpp / 8, getadrr->sizeline, getadrr->endian);
	while (pts.y < 150)
	{
		pts.x = 50;
		while (pts.x < 300)
		{
			//mlx_pixel_put(ptr.mlx, ptr.win, pts.x, pts.y, 0x00FFFFFF);
			getadrr->data[getadrr->sizeline * pts.y + (getadrr->bpp / 8) * pts.x] = color & 0x00FF0000 >> 16;
			getadrr->data[getadrr->sizeline * pts.y + (getadrr->bpp / 8) * pts.x + 1] = color & 0x00FF00 >> 8;
			getadrr->data[getadrr->sizeline * pts.y + (getadrr->bpp / 8) * pts.x + 2] = color & 0x00FF;
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
