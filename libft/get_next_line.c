/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: signetriste <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 19:54:09 by signetris         #+#    #+#             */
/*   Updated: 2017/10/28 19:54:12 by signetris        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/get_next_line.h"

static t_gnl	*buff_rest(int fd, t_gnl **list)
{
	t_gnl	*tmp;
	t_gnl	*new;

	tmp = *list;
	while (tmp)
	{
		if (fd == (int)(tmp->filed))
			return (tmp);
		tmp = tmp->next;
	}
	tmp = *list;
	new = ft_lstnew2("\0", fd);
	ft_lstadd2(list, new);
	return (*list);
}

static int		read_next_line(const int fd, char *buff, t_gnl *buffrest)
{
	int		ret;

	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		buffrest->content = ft_memcat(buffrest, buff);
		if (ft_strchr(buffrest->content, '\n') != NULL)
			break ;
	}
	return (ret);
}

int				get_next_line(const int fd, char **line)
{
	int				ret;
	int				i;
	static t_gnl	*list;
	t_gnl			*buffrest;
	char			buff[BUFF_SIZE + 1];

	if (!line || fd < 0 || read(fd, buff, 0) == -1)
		return (-1);
	buffrest = buff_rest(fd, &list);
	ret = read_next_line(fd, buff, buffrest);
	if (ret < BUFF_SIZE && !ft_strlen(buffrest->content))
		return (0);
	i = ft_strchr2(buffrest->content, '\n');
	if (i == -1)
		i = ft_strlen(buffrest->content);
	*line = ft_strsub(buffrest->content, 0, i);
	if (ft_strchr2(buffrest->content, '\n') == -1 && !ret)
		i--;
	if (ft_strchr2(buff, '\n') < BUFF_SIZE)
		buffrest->content += i + 1;
	else
		ft_strclr(buffrest->content);
	return (1);
}
