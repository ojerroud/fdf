# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ojerroud <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/26 16:57:41 by ojerroud          #+#    #+#              #
#    Updated: 2017/11/08 14:16:20 by ojerroud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = fdf.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -o

MINIFLAGS = -L. -lmlx -framework OpenGL -framework AppKit

LIBFLAGS = -L libft/ -lft

CC = gcc

INCDIR = -I minilibx_macos/ -I libft/

all : $(NAME)

$(NAME):
	make -C libft/
	make -C minilibx_macos/
	$(CC) $(CFLAGS) $(NAME) $(SRC) $(INCDIR) $(MINIFLAGS) $(LIBFLAGS)

recomp:
	$(CC) $(CFLAGS) $(NAME) $(SRC) $(INCDIR) $(MINIFLAGS) $(LIBFLAGS)

test:
	$(CC) $(CFLAGS) test_fdf test.c $(INCDIR) $(MINIFLAGS) $(LIBFLAGS)

clean : 
	make clean -C libft
	/bin/rm -f $(OBJ)

fclean : clean
	make fclean -C libft
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all $(NAME) clean fclean re