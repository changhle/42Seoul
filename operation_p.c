#include "push_swap.h"

void pa(t_info *info)
{
	t_node *temp;

	if (info->b_size < 1)
		return;
	temp = info->b_top;
	info->b_top = info->b_top->prev;
	if (info->a_size == 0)
	{
		temp->prev = NULL;
		info->a_top = temp;
		info->a_bottom = temp;
	}
	else
	{
		info->a_top->next = temp;
		temp->prev = info->a_top;
		info->a_top = temp;
	}
	info->a_size++;
	info->b_size--;
	write(1, "pa\n", 3);
}

void pb(t_info *info)
{
	t_node *temp;

	if (info->a_size < 1)
		return;
	temp = info->a_top;
	info->a_top = info->a_top->prev;
	if (info->b_size == 0)
	{
		temp->prev = NULL;
		info->b_top = temp;
		info->b_bottom = temp;
	}
	else
	{
		info->b_top->next = temp;
		temp->prev = info->b_top;
		info->b_top = temp;
	}
	info->a_size--;
	info->b_size++;
	write(1, "pb\n", 3);
}