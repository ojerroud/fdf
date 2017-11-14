/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 16:05:44 by ojerroud          #+#    #+#             */
/*   Updated: 2017/10/31 16:05:48 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdio.h>

t_gnl	*ft_lstnew2(char const *content, size_t filed)
{
	t_gnl	*tmp;

	if (!(tmp = (t_gnl *)malloc(sizeof(t_gnl))))
		return (NULL);
	if (!(tmp->content = ft_strnew(ft_strlen((char *)content))))
		return (NULL);
	ft_strcpy(tmp->content, (char *)content);
	tmp->head = tmp->content;
	tmp->filed = filed;
	tmp->next = NULL;
	return (tmp);
}
