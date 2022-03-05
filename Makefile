CC = clang
CFLAGS = -Wall -Wextra -Werror

LIBFT = libft
LIBFT_LIB = libft.a
NAME = libftprintf.a
SRCS = ft_printf.c \
		type_percent.c \
		type_c.c \
		type_s.c \
		type_diu.c \
		type_pxX.c \
		utils.c
OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	make -C $(LIBFT) all
	cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	ar rcs $(NAME) $(OBJS)

$(OBJS) : $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS)

all : $(NAME)

bonus : all

clean :
	make -C $(LIBFT) clean
	rm -f $(OBJS)

fclean : clean
	make -C $(LIBFT) fclean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
