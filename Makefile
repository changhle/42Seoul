CC = gcc
CFLALGS = -Wall -Werror -Wextra
LIBFT = libft
LIBFT_LIB = libft.a
NAME = push_swap
SRCS = hard_sort.c\
	operation_p.c\
	operation_r.c\
	operation_rr.c\
	operation_s.c\
	push_swap.c\
	a_to_b_to_a.c\
	select_pivot.c\
	sort.c\
	ft_atoll.c\
	ft_isdigit.c\
	ft_split.c
OBJS = $(SRCS_C:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(SRCS) -o $(NAME)

bonus : all

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all