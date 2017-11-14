/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 13:15:07 by ojerroud          #+#    #+#             */
/*   Updated: 2017/08/08 16:50:29 by signetris        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static void	signe_atoi(char *str, int *i, int *signe)
{
	if (str[*i] == '-')
	{
		*signe = -1;
		(*i)++;
	}
	else if (str[*i] == '+')
	{
		(*i)++;
	}
	else if (str[*i] < '0' || str[*i] > '9')
		signe = 0;
}

int			ft_atoi(char *str)
{
	int atoi;
	int i;
	int signe;

	signe = 1;
	i = 0;
	atoi = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	signe_atoi(str, &i, &signe);
	if (signe == 0)
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (str[i] >= '0' && str[i] <= '9')
			atoi = atoi * 10 + (str[i] - 48);
		i++;
	}
	atoi *= signe;
	return (atoi);
}
