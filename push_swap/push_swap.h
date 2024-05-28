/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 13:32:54 by changhle          #+#    #+#             */
/*   Updated: 2022/06/26 09:45:33 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_node
{
	int				content;
	char			*command;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_info
{
	int		a_size;
	int		b_size;
	int		cmd;
	t_node	*a_top;
	t_node	*a_bottom;
	t_node	*b_top;
	t_node	*b_bottom;
	t_node	*cmd_top;
	t_node	*cmd_bottom;
}	t_info;

typedef struct s_var
{
	int	ra_cnt;
	int	rb_cnt;
	int	pa_cnt;
	int	pb_cnt;
	int	l_pivot;
	int	s_pivot;
	int	m_pivot;
}	t_var;

void		init_var(t_var *var);
void		init_info(t_info *info);
void		fill_stack(t_info *info, char **argv);
void		push_to_stack_a(char *arr, t_info *info);
void		push_to_stack_command(t_info *info, char *str);
void		sort_3_5(t_info *info);
void		a_to_b(t_info *info, int r);
void		b_to_a(t_info *info, int r);
void		hard_sort(t_info *info, int size, char stack);
void		a_2(t_info *info, int a, int b);
void		b_2(t_info *info, int a, int b);
void		select_pivot(t_node *temp, int r, int *s_pivot, int *l_pivot);
void		select_mid_pivot(t_node *temp, int r, int *pivot);
void		optimize(t_info *info);

void		operation(t_info *info, char *opt, int bonus);
void		pa(t_info *info);
void		pb(t_info *info);
void		ra(t_info *info);
void		rb(t_info *info);
void		rr(t_info *info);
void		rra(t_info *info);
void		rrb(t_info *info);
void		rrr(t_info *info);
void		sa(t_info *info);
void		sb(t_info *info);
void		ss(t_info *info);

long long	ft_atoll(const char *str);
int			ft_strcmp(char *str1, char *str2);
void		print_error(int errno);
void		free_all(t_info *info);
void		check_overlap(t_info *info);

#endif