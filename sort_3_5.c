/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 19:21:39 by changhle          #+#    #+#             */
/*   Updated: 2022/06/26 09:11:53 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_3(t_info *info, int a, int b, int c)
{
	if ((a < c && c < b) || (b < c && c < a))
		operation(info, "ra", 0);
	if ((a < c && c < b) || (b < a && a < c) || (c < b && b < a))
		operation(info, "sa", 0);
	if ((a < c && c < b) || (c < a && a < b) || (c < b && b < a))
		operation(info, "rra", 0);
}

void	sort_3_5(t_info *info)
{
	int	i;
	int	m_pivot;

	i = 0;
	if (info->a_size == 5)
	{
		select_mid_pivot(info->a_top, 5, &m_pivot);
		while (i < 5)
		{
			if (info->a_top->content >= m_pivot)
				operation(info, "ra", 0);
			else
				operation(info, "pb", 0);
			i++;
		}
	}
	sort_3(info, info->a_top->content, info->a_top->next->content,
		info->a_top->next->next->content);
	if (i == 5)
		b_2(info, info->b_top->content, info->b_top->next->content);
}
