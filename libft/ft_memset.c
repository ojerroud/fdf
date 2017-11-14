/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 14:05:43 by ojerroud          #+#    #+#             */
/*   Updated: 2017/04/18 18:59:29 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memset(void *pointor, int value, size_t len)
{
	unsigned int	i;
	unsigned char	val;
	unsigned char	*str;

	str = (unsigned char *)pointor;
	val = (unsigned char)value;
	i = 0;
	while (i < len)
	{
		str[i] = val;
		i++;
	}
	return (pointor);
}
