/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 15:13:11 by ojerroud          #+#    #+#             */
/*   Updated: 2017/04/28 12:27:22 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_gnl
{
	char			*content;
	char			*head;
	size_t			filed;
	struct s_gnl	*next;
}					t_gnl;

void				*ft_memset(void *pointor, int value, size_t len);

void				*ft_memalloc(size_t	size);

void				ft_memdel(void **ap);

char				*ft_strnew(size_t size);

void				ft_strdel(char	**as);

size_t				ft_strlen(char *str);

void				ft_strclr(char *s);

void				ft_striter(char *s, void (*f)(char *));

void				ft_striteri(char *s, void (*f)(unsigned int, char *));

char				*ft_strmap(char const *s, char (*f)(char));

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

int					ft_strcmp(char *s1, char *s2);

int					ft_strequ(char const *s1, char const *s2);

int					ft_strnequ(char const *s1, char const *s2, size_t n);

char				*ft_strsub(char const *s, unsigned int start, size_t len);

char				*ft_strjoin(char const *s1, char const *s2);

char				*ft_strcpy(char *dest, char *src);

char				*ft_strtrim(char const *s);

char				**ft_strsplit(char const *s, char c);

char				*ft_itoa(int n);

void				ft_putchar(char c);

void				ft_putstr(char *str);

void				ft_putendl(char const *s);

void				ft_putnbr(int n);

void				ft_putchar_fd(char c, int fd);

void				ft_putstr_fd(char const *s, int fd);

void				ft_putstr_fd(char const *s, int fd);

void				ft_putendl_fd(char const *s, int fd);

void				ft_putnbr_fd(int n, int fd);

int					ft_atoi(char *str);

char				*ft_strcat(char *dest, char *src);

char				*ft_strdup(char *src);

char				*ft_strncat(char *dest, char *src, int nb);

int					ft_strncmp(char *s1, char *s2, unsigned int n);

char				*ft_strncpy(char *dest, char *src, unsigned int n);

char				*ft_strstr(char *str, char *to_find);

void				ft_bzero(void	*s, unsigned int n);

void				*ft_memcpy(void *dst, const void *src, unsigned int n);

void				*ft_memccpy(void *dst, const void *src,
		int c, unsigned int n);

void				*ft_memmove(void *dst, const void *src, unsigned int len);

void				*ft_memchr(const void *s, int c, unsigned int n);

int					ft_memcmp(const void *s1, const void *s2, unsigned int n);

unsigned int		ft_strlcat(char *dst, const char *src, unsigned int size);

char				*ft_strchr(const char *s, int c);

char				*ft_strrchr(const char *s, int c);

int					ft_isalpha(int c);

int					ft_isdigit(int c);

int					ft_isalnum(int c);

int					ft_isascii(int c);

int					ft_isprint(int c);

int					ft_toupper(int c);

int					ft_tolower(int c);

char				*ft_strnstr(char *str, char *to_find, unsigned int len);

t_list				*ft_lstnew(void const *content, size_t content_size);

t_gnl				*ft_lstnew2(char const *content, size_t filed);

void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));

void				ft_lstdel(t_list **alst, void (*del)(void*, size_t));

void				ft_lstadd(t_list **alst, t_list *new);

void				ft_lstadd2(t_gnl **alst, t_gnl *new);

void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

t_list				*ft_lst_last(t_list *begin_list);

size_t				ft_lst_size(t_gnl *begin_list);

void				ft_lstaddend(t_list *alst, t_list *new);

t_list				*ft_lstfind(t_list *begin_list, void *data_ref);

void				ft_lstmerge(t_list *begin_list1, t_list *begin_list2);

void				ft_lstprint(t_gnl *list);

char				*ft_strendcpy(char *dest, char *src);

char				*ft_strendncpy(char *dest, char *src, unsigned int n);

int					ft_strchr2(const char *s, char c);

char				*ft_remalloc(char *src, int size);

char				*ft_memcat(t_gnl *s1, char *s2);

int					get_next_line(const int fd, char **line);

#endif
