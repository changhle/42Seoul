#include "push_swap.h"

int select_pivot(int size_i, t_info *sorted_list)
{
	int i;
	t_node *temp;

	i = 0;
	temp = sorted_list->a_bottom;
	while (i < size_i)
	{
		temp = temp->next;
		i++;
	}
	return (temp->content);
}