#include "new_push_swap.h"

void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void sort(t_info *info)
{
	int i;
	int j;
	t_node *temp_i;
	t_node *temp_j;

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

void sort_arr(int *arr, int r)
{
	int i;
	int j;

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

void select_pivot(t_info *info, int r, int *s_pivot, int *l_pivot, char stack)
{
	int i;
	int *arr;
	t_node *temp;

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
	*s_pivot = arr[r / 3];
	*l_pivot = arr[(r * 2) / 3];
	free(arr);
	// printf("sp = %d\nlp = %d\n", *s_pivot, *l_pivot);
}

int is_sorted(t_info *info, int r)
{
	int i;
	t_node *temp;

	i = 0;
	temp = info->a_top;
	while (i < r - 1)
	{
		if (temp->content > temp->next->content)
			return (0);
		temp = temp->next;
		i++;
	}
	return (1);
}

int is_rsorted(t_info *info, int r)
{
	int i;
	t_node *temp;

	i = 0;
	temp = info->b_top;
	while (i < r - 1)
	{
		if (temp->content < temp->next->content)
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