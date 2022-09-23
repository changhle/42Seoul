CC = gcc
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