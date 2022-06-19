# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/17 13:32:46 by changhle          #+#    #+#              #
#    Updated: 2022/06/19 11:13:39 by changhle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLALGS = -Wall -Werror -Wextra
LIBFT = libft
LIBFT_LIB = libft.a
NAME = push_swap
SRCS = main.c\
	hard_sort.c\
	operation_p.c\
	operation_r.c\
	operation_rr.c\
	operation_s.c\
	push_swap.c\
	a_to_b_to_a.c\
	select_pivot.c\
	sort.c\
	utils.c\
	ft_isdigit.c\
	ft_split.c\
	optimize.c\
	operation.c
SRCS_B = hard_sort.c\
	operation_p.c\
	operation_r.c\
	operation_rr.c\
	operation_s.c\
	push_swap.c\
	a_to_b_to_a.c\
	select_pivot.c\
	sort.c\
	utils.c\
	ft_isdigit.c\
	ft_split.c\
	optimize.c\
	operation.c\
	checker.c
OBJS = $(SRCS_C:.c=.o)
OBJS_B = $(SRCS_C:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) -g $(SRCS) -o $(NAME)

bonus : $(OBJS_B)
	$(CC) -g $(SRCS_B) -o checker

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all