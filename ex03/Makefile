CXX		= c++ -std=c++98
CFLAGS	= -Wall -Werror -Wextra
NAME	= War
SRCS	= Weapon.cpp HumanA.cpp HumanB.cpp main.cpp
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