#include "new_push_swap.h"

void sa(t_info *info)
{
	int temp;

	if (info->a_size > 1)
	{
		temp = info->a_top->content;
		info->a_top->content = info->a_top->next->content;
		info->a_top->next->content = temp;
		info->cmd++;
		push_to_stack_command(info, "sa\n");
		// write(1, "sa\n", 3);
		print_stack(info);
	}
}

void sb(t_info *info)
{
	int temp;

	if (info->b_size > 1)
	{
		temp = info->b_top->content;
		info->b_top->content = info->b_top->next->content;
		info->b_top->next->content = temp;
		info->cmd++;
		push_to_stack_command(info, "sb\n");
		// write(1, "sb\n", 3);
		print_stack(info);
	}
}

void ss(t_info *info)
{
	int temp;

	if (info->a_size > 1)
	{
		temp = info->a_top->content;
		info->a_top->content = info->a_top->next->content;
		info->a_top->next->content = temp;
	}
	if (info->b_size > 1)
	{
		temp = info->b_top->content;
		info->b_top->content = info->b_top->next->content;
		info->b_top->next->content = temp;
	}
	info->cmd++;
	push_to_stack_command(info, "ss\n");
	// write(1, "ss\n", 3);
	print_stack(info);
}