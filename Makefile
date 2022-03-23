
CC = gcc
CFLALGS = -Wall -Werror -Wextra
LIBFT = libft
LIBFT_LIB = libft.a
NAME = minitalk
CLIENT = client
SERVER = server
SRCS_C = client.c
SRCS_S = server.c
OBJS_C = $(SRCS_C:.c=.o)
OBJS_S = $(SRCS_S:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS_C) $(OBJS_S)
	make -C $(LIBFT) all
	$(CC) $(OBJS_C) $(LIBFT)/$(LIBFT_LIB) -o $(CLIENT)
	$(CC) $(OBJS_S) $(LIBFT)/$(LIBFT_LIB) -o $(SERVER)

bonus : all

clean :
	make -C $(LIBFT) clean
	rm -f $(OBJS_C) $(OBJS_S)

fclean : clean
	make -C $(LIBFT) fclean
	rm -f $(CLIENT) $(SERVER)

re : fclean all