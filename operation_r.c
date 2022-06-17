/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 13:27:15 by changhle          #+#    #+#             */
/*   Updated: 2022/06/17 19:49:36 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_info *info)
{
	t_node	*temp;

	if (info->a_size > 1)
	{
		temp = info->a_top;
		info->a_top = info->a_top->next;
		info->a_top->prev = NULL;
		info->a_bottom->next = temp;
		temp->next = NULL;
		temp->prev = info->a_bottom;
		info->a_bottom = temp;
		info->cmd++;
		push_to_stack_command(info, "ra");
	}
}

void	rb(t_info *info)
{
	t_node	*temp;

	if (info->b_size > 1)
	{
		temp = info->b_top;
		info->b_top = info->b_top->next;
		info->b_top->prev = NULL;
		info->b_bottom->next = temp;
		temp->next = NULL;
		temp->prev = info->b_bottom;
		info->b_bottom = temp;
		info->cmd++;
		push_to_stack_command(info, "rb");
	}
}

void	rr(t_info *info)
{
	t_node	*temp;

	if (info->a_size > 1 && info->b_size > 1)
	{
		temp = info->a_top;
		info->a_top = info->a_top->next;
		info->a_top->prev = NULL;
		info->a_bottom->next = temp;
		temp->next = NULL;
		temp->prev = info->a_bottom;
		info->a_bottom = temp;
		temp = info->b_top;
		info->b_top = info->b_top->next;
		info->b_top->prev = NULL;
		info->b_bottom->next = temp;
		temp->next = NULL;
		temp->prev = info->b_bottom;
		info->b_bottom = temp;
	}
	info->cmd++;
	push_to_stack_command(info, "rr");
}
