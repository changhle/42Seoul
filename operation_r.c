#include "push_swap.h"

void	ra(t_info *info)
{
	if (info->a_size > 1)
	{
		temp = info->a_top;
		info->a_top = info->a_top->prev;
		info->a_top->next = NULL;
		info->a_bottom->prev = temp;
		temp->next = info->a_bottom;
		temp->prev = NULL;
		info->a_bottom = temp;
		write(1, "ra\n", 3);
	}
}

void	rb(t_info *info)
{
	if (info->b_size > 1)
	{
		temp = info->b_top;
		info->b_top = info->b_top->prev;
		info->b_top->next = NULL;
		info->b_bottom->prev = temp;
		temp->next = info->b_bottom;
		temp->prev = NULL;
		info->b_bottom = temp;
		write(1, "rb\n", 3);
	}
}

void	rr(t_info *info)
{
	if (info->a_size > 1 && info->b_size > 1)
	{
		ra(info);
		rb(info);
		write(1, "rr\n", 3);
	}
}