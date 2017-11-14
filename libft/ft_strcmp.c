/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 15:58:20 by ojerroud          #+#    #+#             */
/*   Updated: 2017/04/19 19:04:33 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;
	unsigned int	diff;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			diff = ((unsigned char*)s1)[i] - ((unsigned char *)s2)[i];
			return (diff);
		}
		i++;
	}
	diff = ((unsigned char *)s1)[i] - ((unsigned char *)s2)[i];
	return (diff);
}
