/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 16:05:16 by ojerroud          #+#    #+#             */
/*   Updated: 2017/04/28 12:04:46 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	int		i;
	t_list	*tmp;
	t_list	*alst;
	t_list	*new;

	new = f(lst);
	alst = new;
	i = 0;
	while (lst)
	{
		if (i != 0)
		{
			tmp = new;
			new = f(lst);
		}
		lst = lst->next;
		if (i != 0)
			tmp->next = new;
		i++;
	}
	return (alst);
}
