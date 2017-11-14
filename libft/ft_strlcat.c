/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 13:41:51 by ojerroud          #+#    #+#             */
/*   Updated: 2017/04/26 12:23:14 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

unsigned int	ft_strlcat(char *dst, const char *src, unsigned int size)
{
	unsigned int	len;
	unsigned int	dst_len;
	unsigned int	i;
	unsigned int	j;

	dst_len = (unsigned int)ft_strlen(dst);
	len = ft_strlen((char *)src);
	if (size <= dst_len)
	{
		len += size;
		return (len);
	}
	len += dst_len;
	j = 0;
	i = 0;
	i = dst_len;
	while (i < size - 1 && src[j] != '\0')
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (len);
}
