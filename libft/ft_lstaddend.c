/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 12:18:01 by ojerroud          #+#    #+#             */
/*   Updated: 2017/04/28 12:18:15 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_lstaddend(t_list *alst, t_list *new)
{
	t_list	*tmp;

	while (alst)
	{
		tmp = alst;
		alst = alst->next;
	}
	tmp->next = new;
	new->next = NULL;
}
