# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/17 03:24:30 by changhle          #+#    #+#              #
#    Updated: 2022/08/17 16:12:27 by changhle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = so_long

SRCS = main.c parse.c graphic.c event.c utils.c \
		get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	make -s -C libft all
	make -C mlx all
	gcc $(CFLAGS) -L./mlx -Imlx -framework OpenGL -framework AppKit libft/libft.a mlx/libmlx.a $(OBJS) -o $(NAME)

clean :
	make -C libft clean
	make -C mlx clean
	rm -rf $(OBJS)

fclean : clean
	make -C libft fclean
	rm -rf $(NAME)

re : fclean all