/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 13:33:17 by changhle          #+#    #+#             */
/*   Updated: 2022/06/19 12:08:06 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	sort_arr(int *arr, int r)
{
	int	i;
	int	j;

	i = r - 1;
	while (i > 0)
	{
		j = 0;
		while (j < i)
		{
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
			j++;
		}
		i--;
	}
}

int	is_sorted(t_info *info, int r, int pivot)
{
	int		i;
	t_node	*temp;

	i = 0;
	temp = info->a_top;
	while (i < r)
	{
		if (temp->content < pivot)
			return (0);
		temp = temp->next;
		i++;
	}
	return (1);
}

int	is_rsorted(t_info *info, int r, int pivot)
{
	int		i;
	t_node	*temp;

	i = 0;
	temp = info->b_top;
	while (i < r)
	{
		if (temp->content >= pivot)
			return (0);
		temp = temp->next;
		i++;
	}
	return (1);
}
