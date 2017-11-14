/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 13:16:04 by ojerroud          #+#    #+#             */
/*   Updated: 2017/04/20 17:30:06 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_memcmp(const void *s1, const void *s2, unsigned int n)
{
	unsigned char	*cast_s1;
	unsigned char	*cast_s2;
	unsigned int	i;
	int				diff;

	cast_s1 = (unsigned char *)s1;
	cast_s2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < (n - 1))
	{
		if (cast_s1[i] != cast_s2[i])
		{
			diff = cast_s1[i] - cast_s2[i];
			return (diff);
		}
		i++;
	}
	diff = cast_s1[i] - cast_s2[i];
	return (diff);
}
