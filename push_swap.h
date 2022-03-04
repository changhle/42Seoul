#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

typedef struct	s_node
{
	int				content;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct	s_info
{
	int		a_size;
	int		b_size;
	t_node	*a_top;
	t_node	*a_bottom;
	t_node	*b_top;
	t_node	*b_bottom;
}	t_info;

int	ft_isdigit(int c);
long long	ft_atoll(const char *str);
char		**ft_split(char const *s, char c);

#endif