# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/25 05:49:49 by changhle          #+#    #+#              #
#    Updated: 2022/09/25 05:49:50 by changhle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLALGS = -Wall -Werror -Wextra
NAME = philo
SRCS = main.c \
		monitor.c \
		parse.c\
		philosophers.c \
		philosophers_utils.c \
		utils.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLALGS) $(OBJS) -pthread -o $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all