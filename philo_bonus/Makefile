# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/25 05:49:53 by changhle          #+#    #+#              #
#    Updated: 2022/11/10 14:40:44 by changhle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra
NAME	=	philo
SRCS	=	main.c monitor.c parse.c utils.c \
			philosophers.c philosophers_utils.c
OBJS	=	$(SRCS:.c=.o)

all		:	$(NAME)

%.o		:	%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME)	:	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -pthread -o $(NAME)

clean	:
	rm -f $(OBJS)

fclean	:	clean
	rm -rf $(NAME)

re		:	fclean all