/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 13:32:23 by changhle          #+#    #+#             */
/*   Updated: 2022/06/17 13:32:24 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_3(t_info *info, int a, int b, int c)
{
	if (info->a_size > 3)
	{
		if ((b < a && a < c) || (b < c && c < a) || (c < b && b < a))
			operation(info, "sa", 0);
		if (((c < b) && (a < c || b < a)) || (c < a && (a < b || b < c)))
		{
			operation(info, "ra", 0);
			operation(info, "sa", 0);
			operation(info, "ra", 0);
		}
		if ((c < a && a < b) || (c < b && b < a))
			operation(info, "sa", 0);
	}
	else
	{
		if ((a < c && c < b) || (b < c && c < a))
			operation(info, "ra", 0);
		if ((a < c && c < b) || (b < a && a < c) || (c < b && b < a))
			operation(info, "sa", 0);
		if ((a < c && c < b) || (c < a && a < b) || (c < b && b < a))
			operation(info, "ra", 0);
	}
}

void	b_3(t_info *info, int a, int b, int c)
{
	if (info->b_size > 3)
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
			operation(info, "rb", 0);
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
	else
	{
		if ((a < c && c < b) || (b < c && c < a))
			operation(info, "rb", 0);
		if ((a < b && b < c) || (c < a && a < b) || (b < c && c < a))
			operation(info, "sb", 0);
		if ((a < b && b < c) || (b < a && a < c) || (b < c && c < a))
			operation(info, "rb", 0);
		operation(info, "pa", 0);
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
		else if (size > 3)
		{
			select_mid_pivot(info, size, &var.m_pivot, 'a');
			while (var.pb_cnt < size / 2)
			{
				if (info->a_top->content >= var.m_pivot)
				{
					operation(info, "ra", 0);
					var.ra_cnt++;
				}
				else
				{
					operation(info, "pb", 0);
					var.pb_cnt++;
				}
			}
			i = 0;
			while (info->a_size > 5 && i++ < var.ra_cnt)
				operation(info, "ra", 0);
			hard_sort(info, size - var.pb_cnt, 'a');
			hard_sort(info, var.pb_cnt, 'b');
		}
	}
	else if (stack == 'b')
	{
		if (size == 3)
			b_3(info, info->b_top->content, info->b_top->next->content,
				info->b_top->next->next->content);
		else if (size == 2)
			b_2(info, info->b_top->content, info->b_top->next->content);
		else if (size > 3)
		{
			select_mid_pivot(info, size, &var.m_pivot, 'b');
			while (var.pa_cnt < (size + 1) / 2)
			{
				if (info->b_top->content < var.m_pivot)
				{
					operation(info, "rb", 0);
					var.rb_cnt++;
				}
				else
				{
					operation(info, "pa", 0);
					var.pa_cnt++;
				}
			}
			i = 0;
			while (info->b_size > 5 && i++ < var.rb_cnt)
				operation(info, "rb", 0);
			hard_sort(info, var.pa_cnt, 'a');
			hard_sort(info, size - var.pa_cnt, 'b');
		}
	}
}
