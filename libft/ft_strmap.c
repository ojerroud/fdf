/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 16:13:06 by ojerroud          #+#    #+#             */
/*   Updated: 2017/04/19 17:15:45 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int					len;
	unsigned int		i;
	char				*str;

	len = 0;
	i = 0;
	if (s == NULL)
		return (NULL);
	len = ft_strlen((char *)s);
	if (!(str = (char *)malloc((sizeof(char) * len) + 1)))
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = f(s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
