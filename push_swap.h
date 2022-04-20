#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

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
	t_node *a_top;
	t_node *a_bottom;
	t_node *b_top;
	t_node *b_bottom;
} t_info;

int ft_isdigit(int c);
long long ft_atoll(const char *str);
char **ft_split(char const *s, char c);
void sort(t_info *info);
int select_pivot(int size_i, t_info *sorted_list);
void a_to_b(int size, int size_i, t_info *info, t_info *sorted_list);
void b_to_a(int size, int size_i, t_info *info, t_info *sorted_list);

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