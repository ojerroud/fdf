/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 16:11:08 by ojerroud          #+#    #+#             */
/*   Updated: 2017/04/26 12:39:13 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	unsigned int	diff;

	i = 0;
	diff = 0;
	if (n == 0)
		return (0);
	while ((s1[i] != '\0' && s2[i] != '\0') && i < n)
	{
		if (s1[i] != s2[i])
		{
			diff = ((unsigned char *)s1)[i] - ((unsigned char *)s2)[i];
			return (diff);
		}
		i++;
	}
	if (i < n)
		diff = ((unsigned char *)s1)[i] - ((unsigned char *)s2)[i];
	return (diff);
}
