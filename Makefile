CC = gcc
CFLALGS = -Wall -Werror -Wextra
LIBFT = libft
LIBFT_LIB = libft.a
NAME = push_swap
SRCS = new_hard_sort.c\
	new_operation_p.c\
	new_operation_r.c\
	new_operation_rr.c\
	new_operation_s.c\
	push_swap.c\
	a_to_b_to_a.c\
	select_pivot.c\
	new_sort.c\
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