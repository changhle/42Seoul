/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_hard_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 19:21:39 by changhle          #+#    #+#             */
/*   Updated: 2022/06/19 19:22:14 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_a_3(t_info *info, int a, int b, int c)
{
	if ((a < c && c < b) || (b < c && c < a))
		operation(info, "ra", 0);
	if ((a < c && c < b) || (b < a && a < c) || (c < b && b < a))
		operation(info, "sa", 0);
	if ((a < c && c < b) || (c < a && a < b) || (c < b && b < a))
		operation(info, "rra", 0);
}

// void	small_b_3(t_info *info, int a, int b, int c)
// {
// 	if ((a < c && c < b) || (b < c && c < a))
// 		operation(info, "rb", 0);
// 	if ((a < b && b < c) || (c < a && a < b) || (b < c && c < a))
// 		operation(info, "sb", 0);
// 	if ((a < b && b < c) || (b < a && a < c) || (b < c && c < a))
// 		operation(info, "rrb", 0);
// 	operation(info, "pa", 0);
// 	operation(info, "pa", 0);
// 	operation(info, "pa", 0);
// }

void	sort_5(t_info *info)
{
	int	i;
	int	m_pivot;

	i = 0;
	select_mid_pivot(info, 5, &m_pivot, 'a');
	while (i < 5)
	{
		if (info->a_top->content >= m_pivot)
			operation(info, "ra", 0);
		else
			operation(info, "pb", 0);
		i++;
	}
	small_a_3(info, info->a_top->content, info->a_top->next->content,
		info->a_top->next->next->content);
	b_2(info, info->b_top->content, info->b_top->next->content);
}
