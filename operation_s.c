/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 13:27:30 by changhle          #+#    #+#             */
/*   Updated: 2022/06/26 09:12:54 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	sa(t_info *info)
{
	int	temp;

	if (info->a_size > 1)
	{
		temp = info->a_top->content;
		info->a_top->content = info->a_top->next->content;
		info->a_top->next->content = temp;
	}
}

void	sb(t_info *info)
{
	int	temp;

	if (info->b_size > 1)
	{
		temp = info->b_top->content;
		info->b_top->content = info->b_top->next->content;
		info->b_top->next->content = temp;
	}
}

void	ss(t_info *info)
{
	int	temp;

	sa(info);
	sb(info);
}
