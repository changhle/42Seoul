#include "push_swap.h"

void	sa(t_info *info)
{
	int	temp;

	if (info->a_size > 1)
	{
		temp = info->a_top->content;
		info->a_top->content = info->a_top->prev->content;
		info->a_top->prev->content = temp;
		write(1, "sa\n", 3);
	}
}

void	sb(t_info *info)
{
	int	temp;

	if (info->b_size > 1)
	{
		temp = info->b_top->content;
		info->b_top->content = info->b_top->prev->content;
		info->b_top->prev->content = temp;
		write(1, "sb\n", 3);
	}
}

void	ss(t_info *info)
{
	if (info->a_size > 1 && info->b_size > 1)
	{
		sa(info);
		sb(info);
		write(1, "ss\n", 3);
	}
}