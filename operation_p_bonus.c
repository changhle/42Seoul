/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_p_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 13:27:41 by changhle          #+#    #+#             */
/*   Updated: 2022/06/26 16:49:36 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include <stdlib.h>

void	operation(t_info *info, char *opt, int bonus)
{
	if (!ft_strcmp(opt, "pa"))
		pa(info);
	else if (!ft_strcmp(opt, "pb"))
		pb(info);
	else if (!ft_strcmp(opt, "ra"))
		ra(info);
	else if (!ft_strcmp(opt, "rb"))
		rb(info);
	else if (!ft_strcmp(opt, "rra"))
		rra(info);
	else if (!ft_strcmp(opt, "rr"))
		rr(info);
	else if (!ft_strcmp(opt, "rrb"))
		rrb(info);
	else if (!ft_strcmp(opt, "rrr"))
		rrr(info);
	else if (!ft_strcmp(opt, "sa"))
		sa(info);
	else if (!ft_strcmp(opt, "sb"))
		sb(info);
	else if (!ft_strcmp(opt, "ss"))
		ss(info);
	if (!bonus)
		push_to_stack_command(info, opt);
}

void	pa(t_info *info)
{
	t_node	*temp;

	if (info->b_size < 1)
		return ;
	temp = info->b_top;
	info->b_top = info->b_top->next;
	if (info->b_size == 1)
		info->b_bottom = NULL;
	else if (info->b_size > 1)
		info->b_top->prev = NULL;
	if (info->a_size == 0)
	{
		temp->next = NULL;
		info->a_top = temp;
		info->a_bottom = temp;
	}
	else
	{
		info->a_top->prev = temp;
		temp->next = info->a_top;
		info->a_top = info->a_top->prev;
	}
	info->a_size++;
	info->b_size--;
}

void	pb(t_info *info)
{
	t_node	*temp;

	if (info->a_size < 1)
		return ;
	temp = info->a_top;
	info->a_top = info->a_top->next;
	if (info->a_size == 1)
		info->a_bottom = NULL;
	else if (info->a_size > 1)
		info->a_top->prev = NULL;
	if (info->b_size == 0)
	{
		temp->next = NULL;
		info->b_top = temp;
		info->b_bottom = temp;
	}
	else
	{
		info->b_top->prev = temp;
		temp->next = info->b_top;
		info->b_top = temp;
	}
	info->a_size--;
	info->b_size++;
}
