/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 11:02:28 by ojerroud          #+#    #+#             */
/*   Updated: 2017/04/26 14:13:00 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, unsigned int n)
{
	unsigned int	i;
	unsigned char	*cast_dst;
	unsigned char	*cast_src;
	unsigned char	charactere;

	cast_dst = (unsigned char *)dst;
	cast_src = (unsigned char *)src;
	charactere = (unsigned char)c;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (cast_src[i] == charactere)
		{
			cast_dst[i] = cast_src[i];
			return (&dst[i + 1]);
		}
		cast_dst[i] = cast_src[i];
		i++;
	}
	return (0);
}
