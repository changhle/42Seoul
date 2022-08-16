CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = so_long

SRCS = main.c parse.c graphic.c event.c utils.c \
		get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	make -C libft all
	make -C mlx all
	gcc $(CFLAGS) -L./mlx -Imlx -framework OpenGL -framework AppKit libft/libft.a mlx/libmlx.a $(OBJS) -D BUFFER_SIZE=42 -o $(NAME)

clean :
	make -C libft clean
	make -C mlx clean
	rm -rf $(OBJS)

fclean : clean
	make -C libft fclean
	rm -rf $(NAME)

re : fclean all