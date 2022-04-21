#include "new_push_swap.h"

void ra(t_info *info)
{
	t_node *temp;

	if (info->a_size > 1)
	{
		temp = info->a_top;
		info->a_top = info->a_top->next;
		info->a_top->prev = NULL;
		info->a_bottom->next = temp;
		temp->next = NULL;
		temp->prev = info->a_bottom;
		info->a_bottom = temp;
		info->cmd++;
		write(1, "ra\n", 3);
	}
}

void rb(t_info *info)
{
	t_node *temp;

	if (info->b_size > 1)
	{
		temp = info->b_top;
		info->b_top = info->b_top->next;
		info->b_top->prev = NULL;
		info->b_bottom->next = temp;
		temp->next = NULL;
		temp->prev = info->b_bottom;
		info->b_bottom = temp;
		info->cmd++;
		write(1, "rb\n", 3);
	}
}

void rr(t_info *info)
{
	t_node *temp;

	if (info->a_size > 1 && info->b_size > 1)
	{
		temp = info->a_top;
		info->a_top = info->a_top->next;
		info->a_top->prev = NULL;
		info->a_bottom->next = temp;
		temp->next = NULL;
		temp->prev = info->a_bottom;
		info->a_bottom = temp;

		temp = info->b_top;
		info->b_top = info->b_top->next;
		info->b_top->prev = NULL;
		info->b_bottom->next = temp;
		temp->next = NULL;
		temp->prev = info->b_bottom;
		info->b_bottom = temp;

		info->cmd++;
		write(1, "rr\n", 3);
	}
}