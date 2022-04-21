#ifndef NEW_PUSH_SWAP_H
#define NEW_PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

typedef struct s_node
{
	int content;
	struct s_node *prev;
	struct s_node *next;
} t_node;

typedef struct s_info
{
	int a_size;
	int b_size;
	int cmd;
	t_node *a_top;
	t_node *a_bottom;
	t_node *b_top;
	t_node *b_bottom;
} t_info;

void a_to_b(t_info *info, int r);
void b_to_a(t_info *info, int r);
void sort(t_info *info);
char **ft_split(char const *s, char c);
int ft_isdigit(int c);
long long ft_atoll(const char *str);
void select_pivot(t_info *info, int r, int *s_pivot, int *l_pivot, char stack);
void print_stack(t_info *info);
void hard_sort(t_info *info, int size, char stack);

void pa(t_info *info);
void pb(t_info *info);
void ra(t_info *info);
void rb(t_info *info);
void rr(t_info *info);
void rra(t_info *info);
void rrb(t_info *info);
void rrr(t_info *info);
void sa(t_info *info);
void sb(t_info *info);
void ss(t_info *info);

#endif