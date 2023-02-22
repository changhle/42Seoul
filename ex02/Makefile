CXX		= c++
CFLAGS	= -Wall -Werror -Wextra
NAME	= account
SRCS	= Account.cpp tests.cpp
OBJS	= $(SRCS:.cpp=.o)

all		: $(NAME)

%.o		: %.c
	$(CXX) $(CFLAGS) -c $< -o $@

$(NAME)	: $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o $(NAME)

clean	:
	rm -rf $(OBJS)

fclean	: clean
	rm -rf $(NAME)

re		: fclean all