/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 13:42:33 by ojerroud          #+#    #+#             */
/*   Updated: 2017/04/19 17:22:50 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memalloc(size_t size)
{
	void	*ret;

	if (!(ret = (void *)malloc(sizeof(ret) * size)))
		return (NULL);
	ft_memset(ret, 0, size);
	return (ret);
}
