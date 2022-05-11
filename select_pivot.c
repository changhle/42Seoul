#include "push_swap.h"

void	select_pivot(t_node *temp, int r, int *s_pivot, int *l_pivot)
{
	int		i;
	int		*arr;

	arr = malloc(sizeof(int) * (r + 1));
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

void	select_mid_pivot(t_info *info, int r, int *pivot, char stack)
{
	int		i;
	int		*arr;
	t_node	*temp;

	arr = malloc(sizeof(int) * (r + 1));
	i = 0;
	if (stack == 'a')
		temp = info->a_top;
	else
		temp = info->b_top;
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
