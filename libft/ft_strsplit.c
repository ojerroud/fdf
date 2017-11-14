/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 10:26:32 by ojerroud          #+#    #+#             */
/*   Updated: 2017/04/28 13:06:03 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static void		nb_words_loop(char const *s, char c, int i, int *nb_w_l)
{
	while (s[i] == c)
		i++;
	if (s[i] != '\0')
		(*nb_w_l)++;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			(*nb_w_l)++;
		i++;
	}
}

static char		*nb_letters_loop(char const *s, char **tab, char c, int *nb_w_l)
{
	int	j;
	int i;

	i = 0;
	j = 0;
	while (s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		if (s[i] != c)
			(*nb_w_l)++;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			if (!(tab[j] = (char *)malloc(sizeof(**tab) * ((*nb_w_l) + 1))))
				return (NULL);
			tab[j][*nb_w_l] = '\0';
			(*nb_w_l) = 0;
			j++;
		}
		i++;
	}
	return ("ok");
}

static void		str_copy_to_table(char const *s, char **tab, char c, int i)
{
	int j;
	int k;

	j = 0;
	k = 0;
	while (s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			tab[j][k] = s[i];
			k++;
		}
		if (s[i] == c && s[i + 1] != c)
		{
			j++;
			k = 0;
		}
		i++;
	}
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		nb_w_l;

	tab = NULL;
	i = 0;
	nb_w_l = 0;
	if (s == NULL)
		return (NULL);
	nb_words_loop(s, c, i, &nb_w_l);
	if (!(tab = (char **)malloc(sizeof(*tab) * (nb_w_l + 1))))
		return (NULL);
	tab[nb_w_l] = NULL;
	nb_w_l = 0;
	if ((nb_letters_loop(s, tab, c, &nb_w_l)) == NULL)
		return (NULL);
	str_copy_to_table(s, tab, c, i);
	return (tab);
}
