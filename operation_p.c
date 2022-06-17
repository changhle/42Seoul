/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 13:27:41 by changhle          #+#    #+#             */
/*   Updated: 2022/06/17 19:49:24 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	push_to_stack_command(info, "pa");
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
	push_to_stack_command(info, "pb");
}
