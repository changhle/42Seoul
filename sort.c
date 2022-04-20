#include "push_swap.h"

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

	temp_i = info->a_bottom;
	i = info->a_size - 1;
	while (i > 0)
	{
		temp_j = temp_i;
		j = 0;
		while (j < i)
		{
			if (temp_j->content < temp_j->next->content)
				swap(&temp_j->content, &temp_j->next->content);
			temp_j = temp_j->next;
			j++;
		}
		i--;
	}
}