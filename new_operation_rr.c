#include "new_push_swap.h"

void rra(t_info *info)
{
	t_node *temp;

	if (info->a_size > 1)
	{
		temp = info->a_bottom;
		info->a_bottom = info->a_bottom->prev;
		info->a_bottom->next = NULL;
		info->a_top->prev = temp;
		temp->next = info->a_top;
		temp->prev = NULL;
		info->a_top = temp;
		info->cmd++;
		write(1, "rra\n", 4);
		print_stack(info);
	}
}

void rrb(t_info *info)
{
	t_node *temp;

	if (info->b_size > 1)
	{
		temp = info->b_bottom;
		info->b_bottom = info->b_bottom->prev;
		info->b_bottom->next = NULL;
		info->b_top->prev = temp;
		temp->next = info->b_top;
		temp->prev = NULL;
		info->b_top = temp;
		info->cmd++;
		write(1, "rrb\n", 4);
		print_stack(info);
	}
}

void rrr(t_info *info)
{
	t_node *temp;

	if (info->a_size > 1)
	{
		temp = info->a_bottom;
		info->a_bottom = info->a_bottom->prev;
		info->a_bottom->next = NULL;
		info->a_top->prev = temp;
		temp->next = info->a_top;
		temp->prev = NULL;
		info->a_top = temp;
	}
	if (info->b_size > 1)
	{
		temp = info->b_bottom;
		info->b_bottom = info->b_bottom->prev;
		info->b_bottom->next = NULL;
		info->b_top->prev = temp;
		temp->next = info->b_top;
		temp->prev = NULL;
		info->b_top = temp;
	}
	info->cmd++;
	write(1, "rrr\n", 4);
	print_stack(info);
}