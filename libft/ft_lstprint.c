/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 12:14:36 by ojerroud          #+#    #+#             */
/*   Updated: 2017/04/28 12:15:01 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_lstprint(t_gnl *list)
{
	while (list)
	{
		ft_putstr((char *)list->content);
		list = list->next;
	}
}
