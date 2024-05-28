# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/17 03:24:30 by changhle          #+#    #+#              #
#    Updated: 2022/09/10 07:17:48 by changhle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = so_long
BONUS = so_long_bonus

SRCS_M = src/main.c \
			src/parse.c \
			src/convert_image.c \
			src/print_image.c \
			src/event.c \
			src/utils.c \
			get_next_line/get_next_line.c \
			get_next_line/get_next_line_utils.c
SRCS_B = src_bonus/main.c \
			src_bonus/parse.c \
			src_bonus/convert_image.c \
			src_bonus/print_image.c \
			src_bonus/event.c \
			src_bonus/utils.c \
			get_next_line/get_next_line.c \
			get_next_line/get_next_line_utils.c

OBJS_M = $(SRCS_M:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

all : $(NAME)

bonus : $(BONUS)

$(NAME) : $(OBJS_M)
	make -s -C libft all
	make -C mlx all
	gcc $(CFLAGS) -L./mlx -Imlx -framework OpenGL -framework AppKit ./libft/libft.a ./mlx/libmlx.a $(OBJS_M) -o $(NAME)

$(BONUS) : $(OBJS_B)
	make -s -C libft all
	make -C mlx all
	gcc $(CFLAGS) -L./mlx -Imlx -framework OpenGL -framework AppKit ./libft/libft.a ./mlx/libmlx.a $(OBJS_B) -o $(BONUS)

clean :
	make -C libft clean
	make -C mlx clean
	rm -f $(OBJS_M)
	rm -f $(OBJS_B)

fclean : clean
	make -C libft fclean
	rm -f $(NAME)
	rm -f $(BONUS)

re : fclean all