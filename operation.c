/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 07:09:47 by changhle          #+#    #+#             */
/*   Updated: 2022/06/19 16:13:55 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
