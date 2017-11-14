/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmerge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 12:16:54 by ojerroud          #+#    #+#             */
/*   Updated: 2017/04/28 12:18:47 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_lstmerge(t_list *begin_list1, t_list *begin_list2)
{
	t_list	*tmp;

	while (begin_list1)
	{
		tmp = begin_list1;
		begin_list1 = tmp->next;
	}
	tmp->next = begin_list2;
}
