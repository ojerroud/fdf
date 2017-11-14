/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 12:46:32 by ojerroud          #+#    #+#             */
/*   Updated: 2017/04/21 17:30:43 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memmove(void *dst, const void *src, unsigned int len)
{
	unsigned char	*cast_dst;
	unsigned char	*cast_src;

	cast_dst = (unsigned char *)dst;
	cast_src = (unsigned char *)src;
	if (cast_dst > cast_src)
		while (len--)
			cast_dst[len] = cast_src[len];
	else if (cast_dst == cast_src)
		return (dst);
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
