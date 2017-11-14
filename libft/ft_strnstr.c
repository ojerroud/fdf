/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 16:06:09 by ojerroud          #+#    #+#             */
/*   Updated: 2017/04/27 18:39:23 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnstr(char *str, char *to_find, unsigned int len)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	i = 0;
	j = 0;
	k = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i] != '\0' && (i + j) < len)
	{
		if (str[i + j] == to_find[j])
			j++;
		else
		{
			j = 0;
			i++;
		}
		if (to_find[j] == '\0')
			return (&str[i]);
	}
	return (NULL);
}
