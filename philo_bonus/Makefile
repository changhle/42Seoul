# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/25 05:49:53 by changhle          #+#    #+#              #
#    Updated: 2022/11/09 03:13:11 by changhle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	cc
CFLALGS	=	-Wall -Werror -Wextra
NAME	=	philo
SRCS	=	main.c monitor.c parse.c utils.c \
			philosophers.c philosophers_utils.c
OBJS	=	$(SRCS:.c=.o)

all		:	$(NAME)

$(NAME)	:	$(OBJS)
	$(CC) $(CFLALGS) $(OBJS) -pthread -o $(NAME)

clean	:
	rm -f $(OBJS)

fclean	:	clean
	rm -rf $(NAME)

re		:	fclean all