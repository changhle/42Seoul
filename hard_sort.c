/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 13:32:23 by changhle          #+#    #+#             */
/*   Updated: 2022/06/26 08:51:47 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	a_3(t_info *info, int a, int b, int c)
{
	if ((b < a && a < c) || (b < c && c < a) || (c < b && b < a))
		operation(info, "sa", 0);
	if (((c < b) && (a < c || b < a)) || (c < a && (a < b || b < c)))
	{
		operation(info, "ra", 0);
		operation(info, "sa", 0);
		operation(info, "rra", 0);
	}
	if ((c < a && a < b) || (c < b && b < a))
		operation(info, "sa", 0);
}

static void	b_3(t_info *info, int a, int b, int c)
{
	if ((a < c && c < b) || (c < a && a < b))
		operation(info, "sb", 0);
	if ((a < b && b < c) || (b < a && a < c))
	{
		operation(info, "rb", 0);
		operation(info, "sb", 0);
		operation(info, "pa", 0);
		if (a < b && b < c)
			operation(info, "pa", 0);
		operation(info, "rrb", 0);
	}
	if ((a < c && c < b) || (b < c && c < a))
	{
		operation(info, "pa", 0);
		operation(info, "sb", 0);
	}
	if ((a < b && b < c) || (c < a && a < b) || (c < b && b < a))
		operation(info, "pa", 0);
	if (!(a < b && b < c))
	{
		operation(info, "pa", 0);
		operation(info, "pa", 0);
	}
}

void	a_2(t_info *info, int a, int b)
{
	if (a > b)
		operation(info, "sa", 0);
}

void	b_2(t_info *info, int a, int b)
{
	if (a < b)
		operation(info, "sb", 0);
	operation(info, "pa", 0);
	operation(info, "pa", 0);
}

void	hard_sort(t_info *info, int size, char stack)
{
	int		i;
	t_var	var;

	init_var(&var);
	if (stack == 'a')
	{
		if (size == 3)
			a_3(info, info->a_top->content, info->a_top->next->content,
				info->a_top->next->next->content);
		else if (size == 2)
			a_2(info, info->a_top->content, info->a_top->next->content);
	}
	else if (stack == 'b')
	{
		if (size == 3)
			b_3(info, info->b_top->content, info->b_top->next->content,
				info->b_top->next->next->content);
		else if (size == 2)
			b_2(info, info->b_top->content, info->b_top->next->content);
	}
}
