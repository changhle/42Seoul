#include "push_swap.h"

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	sort(t_info *info)
{
	int		i;
	int		j;
	t_node	*temp_i;
	t_node	*temp_j;

	temp_i = info->a_top;
	i = info->a_size - 1;
	while (i > 0)
	{
		temp_j = temp_i;
		j = 0;
		while (j < i)
		{
			if (temp_j->content > temp_j->next->content)
				swap(&temp_j->content, &temp_j->next->content);
			temp_j = temp_j->next;
			j++;
		}
		i--;
	}
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

	// if (r == 1)
	// 	return (0);
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

	// if (r == 1)
	// 	return (0);
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

void print_stack(t_info *info)
{
	// int i;
	// t_node *temp;

	// i = 0;
	// temp = info->a_top;
	// printf("A | ");
	// while (temp)
	// {
	// 	printf("%d ", temp->content);
	// 	temp = temp->next;
	// }
	// printf("\n");
	// temp = info->b_top;
	// printf("B | ");
	// i = 0;
	// while (temp)
	// {
	// 	printf("%d ", temp->content);
	// 	temp = temp->next;
	// }
	// printf("\n");
}