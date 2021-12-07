# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: changhle <changhle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/17 20:25:28 by changhle          #+#    #+#              #
#    Updated: 2021/12/07 17:14:06 by changhle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS_M = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
SRCS_B = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJS_M = $(SRCS_M:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)
AR = ar
ARFLAGS = -rcs
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I.

ifdef WITH_BONUS
	OBJS = $(OBJS_M) $(OBJS_B)
else
	OBJS = $(OBJS_M)
endif

all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

bonus :
	@make WITH_BONUS=1 all

clean :
	rm -f $(OBJS_M) $(OBJS_B)

fclean : clean
	rm -f $(NAME)

re : fclean all

%.o : %.c
	$(CC) $(CFLAGS) -c $^

.PHONY : all clean fclean re bonus
