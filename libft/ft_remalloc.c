/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 14:00:05 by ojerroud          #+#    #+#             */
/*   Updated: 2017/10/05 14:00:11 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdio.h>

char	*ft_remalloc(char *src, int size)
{
	char	*tmp;

	if (src == NULL)
		if (!(src = ft_strnew(size)))
			return (NULL);
	if (!(tmp = ft_strnew(ft_strlen(src) + size)))
		return (NULL);
	tmp = ft_strcpy(tmp, src);
	ft_strdel(&(src));
	src = tmp;
	return (src);
}
