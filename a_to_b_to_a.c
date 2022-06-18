/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 13:28:46 by changhle          #+#    #+#             */
/*   Updated: 2022/06/17 13:28:47 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse(t_info *info, t_var *var)
{
	int	i;

	i = 0;
	while (i < var->ra_cnt && i < var->rb_cnt)
	{
		operation(info, "rrr", 0);
		i++;
	}
	while (i < var->ra_cnt)
	{
		operation(info, "rra", 0);
		i++;
	}
	while (i < var->rb_cnt)
	{
		operation(info, "rrb", 0);
		i++;
	}
}

void	a_b_cmd(t_info *info, t_var *var, int r)
{
	if (info->a_top->content >= var->l_pivot)
	{
		if (info->a_size == 2 && info->a_top->next->content < var->l_pivot)
		{
			operation(info, "sa", 0);
			operation(info, "pb", 0);
			var->pb_cnt++;
		}
		else if (!is_sorted(info, r - var->ra_cnt - var->pb_cnt, var->l_pivot))
		{
			operation(info, "ra", 0);
			var->ra_cnt++;
		}
	}
	else
	{
		operation(info, "pb", 0);
		var->pb_cnt++;
		if (info->b_top->content >= var->s_pivot)
		{
			operation(info, "rb", 0);
			var->rb_cnt++;
		}
	}
}

void	b_a_cmd(t_info *info, t_var *var, int r)
{
	if (info->b_top->content < var->s_pivot)
	{
		if (info->b_size == 2 && info->b_top->next->content >= var->l_pivot)
		{
			operation(info, "sb", 0);
			operation(info, "pa", 0);
			var->pa_cnt++;
		}
		else if (!is_rsorted(info, r - var->rb_cnt - var->pa_cnt, var->s_pivot))
		{
			operation(info, "rb", 0);
			var->rb_cnt++;
		}
	}
	else
	{
		operation(info, "pa", 0);
		var->pa_cnt++;
		if (info->a_top->content < var->l_pivot)
		{
			operation(info, "ra", 0);
			var->ra_cnt++;
		}
	}
}

void	a_to_b(t_info *info, int r)
{
	int		i;
	t_var	var;

	init_var(&var);
	if (r <= 5)
	{
		hard_sort(info, r, 'a');
		return ;
	}
	select_pivot(info->a_top, r, &var.s_pivot, &var.l_pivot);
	i = 0;
	while (i++ < r)
		a_b_cmd(info, &var, r);
	reverse(info, &var);
	a_to_b(info, r - var.pb_cnt);
	b_to_a(info, var.rb_cnt);
	b_to_a(info, var.pb_cnt - var.rb_cnt);
}

void	b_to_a(t_info *info, int r)
{
	int		i;
	t_var	var;

	i = 0;
	if (r <= 5)
	{
		if (r == 1)
			operation(info, "pa", 0);
		else
			hard_sort(info, r, 'b');
		return ;
	}
	select_pivot(info->b_top, r, &var.s_pivot, &var.l_pivot);
	i = 0;
	init_var(&var);
	while (i++ < r)
		b_a_cmd(info, &var, r);
	a_to_b(info, var.pa_cnt - var.ra_cnt);
	reverse(info, &var);
	a_to_b(info, var.ra_cnt);
	b_to_a(info, r - var.pa_cnt);
}
