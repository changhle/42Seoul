#include "new_push_swap.h"

void pa(t_info *info)
{
	t_node *temp;

	if (info->b_size < 1)
		return;
	temp = info->b_top;
	if (info->b_size == 1)
	{
		info->b_top = NULL;
		info->b_bottom = NULL;
	}
	if (info->a_size == 0)
	{
		temp->next = NULL;
		info->a_top = temp;
		info->a_bottom = temp;
	}
	else
	{
		info->a_top->prev = temp;
		temp->next = info->a_top;
		info->a_top = temp;
	}
	info->a_size++;
	info->b_size--;
	info->cmd++;
	write(1, "pa\n", 3);
}

void pb(t_info *info)
{
	t_node *temp;

	if (info->a_size < 1)
		return;
	temp = info->a_top;
	if (info->a_size == 1)
	{
		info->a_top = NULL;
		info->a_bottom = NULL;
	}
	if (info->b_size == 0)
	{
		temp->next = NULL;
		info->b_top = temp;
		info->b_bottom = temp;
	}
	else
	{
		info->b_top->prev = temp;
		temp->next = info->b_top;
		info->b_top = temp;
	}
	info->a_size--;
	info->b_size++;
	info->cmd++;
	write(1, "pb\n", 3);
}