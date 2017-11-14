/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 16:52:22 by ojerroud          #+#    #+#             */
/*   Updated: 2017/09/26 17:31:20 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	t_file_param	file;
	int				**tab;
	char			**tmp;
	char			*line;
	int				fd;
	int				ret;
	size_t			i;
	size_t			y;

	if (ac != 2)
		return (1);
	file.height = 0;
	fd = open(av[1], O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		ft_strdel(&line);
		file.height++;
	}
	if (ret == -1)
		return (-1);
	close(fd);
	tab = (int **)malloc(sizeof(int*) * file.height);
	y = 0;
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		tmp = ft_strsplit(line, ' ');
		ft_strdel(&line);
		i = 0;
		while (tmp[i])
			i++;
		file.width = i;
		tab[y] = (int *)malloc(sizeof(int) * i);
		i = -1;
		while (tmp[++i])
		{
			tab[y][i] = ft_atoi(tmp[i]);
			ft_strdel(&tmp[i]);
		}
		y++;
		free(tmp);
	}
	y = 0;
	while (file.height > y)
	{
		i = 0;
		while (file.width > i)
		{
			printf("%d ", tab[y][i]);
		i++;
		}
		printf("\n");
		y++;
	}
	while(1){}
/*
**	fd = open(av[1], O_RDONLY);
**	while ((ret = get_next_line(fd, &line)) > 0)
**		i++;
**	close(fd);
*/
	return (0);
}
