#include "push_swap.h"

void rra(t_info *info)
{
	t_node *temp;

	if (info->a_size > 1)
	{
		temp = info->a_bottom;
		info->a_bottom = info->a_bottom->next;
		info->a_bottom->prev = NULL;
		info->a_top->next = temp;
		temp->prev = info->a_top;
		temp->next = NULL;
		info->a_top = temp;
		write(1, "rra\n", 4);
	}
}

void rrb(t_info *info)
{
	t_node *temp;

	if (info->b_size > 1)
	{
		temp = info->b_bottom;
		info->b_bottom = info->b_bottom->next;
		info->b_bottom->prev = NULL;
		info->b_top->next = temp;
		temp->prev = info->b_top;
		temp->next = NULL;
		info->b_top = temp;
		write(1, "rrb\n", 4);
	}
}

void rrr(t_info *info)
{
	if (info->a_size > 1 && info->b_size > 1)
	{
		rra(info);
		rrb(info);
		write(1, "rrr\n", 4);
	}
}