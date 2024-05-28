# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/15 14:00:52 by changhle          #+#    #+#              #
#    Updated: 2022/04/17 16:11:34 by changhle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = gcc
CFLALGS = -Wall -Werror -Wextra
LIBFT = libft
LIBFT_LIB = libft.a
NAME = libminitalk.a
CLIENT_M = client
SERVER_M = server
CLIENT_B = client_bonus
SERVER_B = server_bonus
SRCS_C = client.c
SRCS_S = server.c
OBJS_C = $(SRCS_C:.c=.o)
OBJS_S = $(SRCS_S:.c=.o)
SRCS_C_BONUS = client_bonus.c
SRCS_S_BONUS = server_bonus.c
OBJS_C_BONUS = $(SRCS_C_BONUS:.c=.o)
OBJS_S_BONUS = $(SRCS_S_BONUS:.c=.o)

ifdef WITH_BONUS
	OBJS_FILE_C = $(OBJS_C_BONUS)
	OBJS_FILE_S = $(OBJS_S_BONUS)
	CLIENT = $(CLIENT_B)
	SERVER = $(SERVER_B)
else
	OBJS_FILE_C = $(OBJS_C)
	OBJS_FILE_S = $(OBJS_S)
	CLIENT = $(CLIENT_M)
	SERVER = $(SERVER_M)

endif

all : $(NAME)

$(NAME) : $(OBJS_FILE_C) $(OBJS_FILE_S)
	make -C $(LIBFT) all
	$(CC) $(OBJS_FILE_C) $(LIBFT)/$(LIBFT_LIB) -o $(CLIENT)
	$(CC) $(OBJS_FILE_S) $(LIBFT)/$(LIBFT_LIB) -o $(SERVER)
	ar rcs $(NAME) $(OBJS_FILE_C) $(OBJS_FILE_S)

bonus : $(OBJS_C_BONUS) $(OBJS_S_BONUS)
	make WITH_BONUS=1 all

clean :
	make -C $(LIBFT) clean
	rm -f $(OBJS_C) $(OBJS_S) $(OBJS_C_BONUS) $(OBJS_S_BONUS)

fclean : clean
	make -C $(LIBFT) fclean
	rm -f $(CLIENT_M) $(SERVER_M) $(CLIENT_B) $(SERVER_B) $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re