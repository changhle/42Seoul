/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_pivot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 13:31:57 by changhle          #+#    #+#             */
/*   Updated: 2022/06/26 09:14:17 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

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

void	select_pivot(t_node *temp, int r, int *s_pivot, int *l_pivot)
{
	int		i;
	int		*arr;

	arr = malloc(sizeof(int) * (r + 1));
	if (!arr)
		print_error(2);
	i = 0;
	while (i < r)
	{
		arr[i] = temp->content;
		temp = temp->next;
		i++;
	}
	sort_arr(arr, r);
	*s_pivot = arr[r / 3];
	*l_pivot = arr[(r * 2) / 3];
	free(arr);
}

void	select_mid_pivot(t_node *temp, int r, int *pivot)
{
	int		i;
	int		*arr;

	arr = malloc(sizeof(int) * (r + 1));
	if (!arr)
		print_error(2);
	i = 0;
	while (i < r)
	{
		arr[i] = temp->content;
		temp = temp->next;
		i++;
	}
	sort_arr(arr, r);
	*pivot = arr[r / 2];
	free(arr);
}
