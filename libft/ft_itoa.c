/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 09:35:10 by ojerroud          #+#    #+#             */
/*   Updated: 2017/04/19 16:39:29 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static void	constructor_char(char *nb, char signe, int n, int len)
{
	int i;

	i = 0;
	if (signe != '\0')
	{
		nb[i] = signe;
		i++;
	}
	i = len - 1;
	while (n >= 10)
	{
		nb[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	nb[i] = n + '0';
}

static void	check_signe_and_len(int *n, int *len, char *signe)
{
	int tmp;

	if (*n < 0)
	{
		*signe = '-';
		*n = -(*n);
		(*len)++;
	}
	tmp = *n;
	while (*n >= 10)
	{
		*n /= 10;
		(*len)++;
	}
	*n = tmp;
}

char		*ft_itoa(int n)
{
	char	*nb;
	char	signe;
	int		len;

	nb = NULL;
	signe = '\0';
	len = 1;
	if (n == (-2147483648))
	{
		if (!(nb = (char *)malloc(sizeof(*nb) * (12))))
			return (NULL);
		ft_strcpy(nb, "-2147483648");
		return (nb);
	}
	check_signe_and_len(&n, &len, &signe);
	if (!(nb = (char *)malloc(sizeof(*nb) * (len + 1))))
		return (0);
	nb[len] = '\0';
	constructor_char(nb, signe, n, len);
	return (nb);
}
