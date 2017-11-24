/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 16:54:17 by ojerroud          #+#    #+#             */
/*   Updated: 2017/09/26 17:16:41 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <stdlib.h>
# include "mlx.h"
# include "libft/includes/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# define WIN_WIDTH	800

/*
** largeur >
*/
# define WIN_HEIGHT	800

/*
** taille /\
*/
# define EDGE_DIST	1

/*
**distance du bord
*/

typedef struct		s_file_param
{
	float	height; // taille (y)
	float	width;  // largeur (x)
}					t_file_param;

typedef struct		s_fdf
{
	void	*mlx;
	void	*win;
}					t_fdf;

typedef struct		s_coord
{
	int		x;
	int		y;
	size_t	z;
}					t_coord;

#endif
