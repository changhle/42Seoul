# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/06 21:02:37 by changhle          #+#    #+#              #
#    Updated: 2022/03/25 19:45:31 by changhle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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
SRCS_BONUS = ft_printf_bonus.c \
				type_percent_bonus.c \
				type_c_bonus.c \
				type_s_bonus.c \
				type_diu_bonus.c \
				type_pxX_bonus.c \
				utils_bonus.c
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

$(NAME) : $(OBJS)
	make -C $(LIBFT) all
	cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	ar rcs $(NAME) $(OBJS)

$(OBJS) : $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS)

$(OBJS_BONUS) : $(SRCS_BONUS)
	$(CC) $(CFLAGS) -c $(SRCS_BONUS)

all : $(NAME)

bonus : all $(OBJS_BONUS)
	ar rcs $(NAME) $(OBJS_BONUS)

clean :
	make -C $(LIBFT) clean
	rm -f $(OBJS) $(OBJS_BONUS)

fclean : clean
	make -C $(LIBFT) fclean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus
