#include "push_swap.h"

void	ra(t_info *info)
{
	t_node	*temp;

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
		push_to_stack_command(info, "ra\n");
		// write(1, "ra\n", 3);
		print_stack(info);
	}
}

void	rb(t_info *info)
{
	t_node	*temp;

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
		push_to_stack_command(info, "rb\n");
		// write(1, "rb\n", 3);
		print_stack(info);
	}
}

void	rr(t_info *info)
{
	t_node	*temp;

	if (info->a_size > 1)
	{
		temp = info->a_top;
		info->a_top = info->a_top->next;
		info->a_top->prev = NULL;
		info->a_bottom->next = temp;
		temp->next = NULL;
		temp->prev = info->a_bottom;
		info->a_bottom = temp;
	}
	if (info->b_size > 1)
	{
		temp = info->b_top;
		info->b_top = info->b_top->next;
		info->b_top->prev = NULL;
		info->b_bottom->next = temp;
		temp->next = NULL;
		temp->prev = info->b_bottom;
		info->b_bottom = temp;
	}
	info->cmd++;
	push_to_stack_command(info, "rr\n");
	// write(1, "rr\n", 3);
	print_stack(info);
}