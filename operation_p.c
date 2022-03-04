#include "push_swap.h"

void	pa(t_info *info)
{
	t_info	*temp;

	if (info->b_size > 0)
	{
		temp = info->b_top;
		info->b_top = info->b_top->prev;
		info->b_top->next = NULL;
		info->a_top->next = temp;
		temp->prev = info->a_top;
		info->a_top = temp;
	}
}