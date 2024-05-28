CXX			= c++ -std=c++98
CXXFLAGS	= -Wall -Werror -Wextra
NAME		= Interface
SRCS		= AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp main.cpp
OBJS		= $(SRCS:.cpp=.o)

all		: $(NAME)

%.o		: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME)	: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean	:
	rm -rf $(OBJS)

fclean	: clean
	rm -rf $(NAME)

re		: fclean all
