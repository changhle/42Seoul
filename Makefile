# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/17 13:32:46 by changhle          #+#    #+#              #
#    Updated: 2022/06/26 09:52:23 by changhle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLALGS = -Wall -Werror -Wextra
LIBFT = libft
LIBFT_LIB = libft.a
NAME = push_swap
BONUS = checker

SRCS_M = main.c\
		push_swap.c\
		quick_sort.c\
		hard_sort.c\
		sort_3_5.c\
		select_pivot.c\
		operation_p.c\
		operation_r.c\
		operation_rr.c\
		operation_s.c\
		optimize.c\
		utils.c

SRCS_B = checker.c\
		push_swap.c\
		operation_p.c\
		operation_r.c\
		operation_rr.c\
		operation_s.c\
		utils.c

OBJS_M = $(SRCS_M:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS_M)
	make -C $(LIBFT) all
	$(CC) $(CFLALGS) $(OBJS_M) $(LIBFT)/$(LIBFT_LIB) -o $(NAME)

$(BONUS) : $(OBJS_B)
	make -C $(LIBFT) all
	$(CC) $(CFLALGS) $(OBJS_B) $(LIBFT)/$(LIBFT_LIB) -o $(BONUS)

bonus : $(BONUS)

clean :
	make -C $(LIBFT) clean
	rm -f $(OBJS_M) $(OBJS_B)

fclean : clean
	make -C $(LIBFT) fclean
	rm -f $(NAME) $(BONUS)

re : fclean all