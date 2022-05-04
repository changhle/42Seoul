#include "new_push_swap.h"

void pa(t_info *info)
{
	t_node *temp;

	if (info->b_size < 1)
		return;
	temp = info->b_top;
	info->b_top = info->b_top->next;
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
	if (info->b_size > 1)
		info->b_top->prev = NULL;
	info->a_size++;
	info->b_size--;
	info->cmd++;
	push_to_stack_command(info, "pa\n");
	// write(1, "pa\n", 3);
	print_stack(info);
}

void pb(t_info *info)
{
	t_node *temp;

	if (info->a_size < 1)
		return;
	temp = info->a_top;
	info->a_top = info->a_top->next;
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
	if (info->a_size > 1)
		info->a_top->prev = NULL;
	info->a_size--;
	info->b_size++;
	info->cmd++;
	push_to_stack_command(info, "pb\n");
	// write(1, "pb\n", 3);
	print_stack(info);
}