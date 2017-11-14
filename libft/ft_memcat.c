/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 15:43:11 by ojerroud          #+#    #+#             */
/*   Updated: 2017/10/05 15:43:14 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_memcat(t_gnl *s1, char *s2)
{
	char			*str;
	unsigned int	i;
	unsigned int	j;

	i = -1;
	j = 0;
	if (s1->content == NULL || s2 == NULL)
		return (0);
	if (!(str = (char *)malloc((sizeof(*str) * (ft_strlen(s1->content) +
							ft_strlen(s2))) + 1)))
		return (NULL);
	while (s1->content[++i] != '\0')
		str[i] = s1->content[i];
	free(s1->head);
	s1->head = str;
	s1->content = NULL;
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}
