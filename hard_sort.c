#include "push_swap.h"

void	a_3(t_info *info, int a, int b, int c)
{
	if (info->a_size > 3)
	{
		if ((b < a && a < c) || (b < c && c < a) || (c < b && b < a))
			sa(info);
		if (((c < b) && (a < c || b < a)) || (c < a && (a < b || b < c)))
		{
			ra(info);
			sa(info);
			rra(info);
		}
		if ((c < a && a < b) || (c < b && b < a))
			sa(info);
	}
	else
	{
		if ((a < c && c < b) || (b < c && c < a))
			ra(info);
		if ((a < c && c < b) || (b < a && a < c) || (c < b && b < a))
			sa(info);
		if ((a < c && c < b) || (c < a && a < b) || (c < b && b < a))
			rra(info);
	}
}

void	b_3(t_info *info, int a, int b, int c)
{
	if (info->b_size > 3)
	{
		if ((a < c && c < b) || (c < a && a < b))
			sb(info);
		if ((a < b && b < c) || (b < a && a < c))
		{
			rb(info);
			sb(info);
			pa(info);
			if (a < b && b < c)
				pa(info);
			rrb(info);
		}
		if ((a < c && c < b) || (b < c && c < a))
		{
			pa(info);
			sb(info);
		}
		if ((a < b && b < c) || (c < a && a < b) || (c < b && b < a))
			pa(info);
		if (!(a < b && b < c))
		{
			pa(info);
			pa(info);
		}
	}
	else
	{
		if ((a < c && c < b) || (b < c && c < a))
			rb(info);
		if ((a < b && b < c) || (c < a && a < b) || (b < c && c < a))
			sb(info);
		if ((a < b && b < c) || (b < a && a < c) || (b < c && c < a))
			rrb(info);
		pa(info);
		pa(info);
		pa(info);
	}
}

void	a_2(t_info *info, int a, int b)
{
	if (a > b)
		sa(info);
}

void	b_2(t_info *info, int a, int b)
{
	if (a < b)
		sb(info);
	pa(info);
	pa(info);
}

void	hard_sort(t_info *info, int size, char stack)
{
	int		i;
	t_var	var;

	init_var(&var);
	if (stack == 'a')
	{
		if (size == 3)
			a_3(info, info->a_top->content, info->a_top->next->content,
				info->a_top->next->next->content);
		else if (size == 2)
			a_2(info, info->a_top->content, info->a_top->next->content);
		else if (size > 3)
		{
			select_mid_pivot(info, size, &var.m_pivot, 'a');
			while (var.pb_cnt < size / 2)
			{
				if (info->a_top->content >= var.m_pivot)
				{
					ra(info);
					var.ra_cnt++;
				}
				else
				{
					pb(info);
					var.pb_cnt++;
				}
			}
			i = 0;
			while (info->a_size > 5 && i++ < var.ra_cnt)
				rra(info);
			hard_sort(info, size - var.pb_cnt, 'a');
			hard_sort(info, var.pb_cnt, 'b');
		}
	}
	else if (stack == 'b')
	{
		if (size == 3)
			b_3(info, info->b_top->content, info->b_top->next->content,
				info->b_top->next->next->content);
		else if (size == 2)
			b_2(info, info->b_top->content, info->b_top->next->content);
		else if (size > 3)
		{
			select_mid_pivot(info, size, &var.m_pivot, 'b');
			while (var.pa_cnt < (size + 1) / 2)
			{
				if (info->b_top->content < var.m_pivot)
				{
					rb(info);
					var.rb_cnt++;
				}
				else
				{
					pa(info);
					var.pa_cnt++;
				}
			}
			i = 0;
			while (info->b_size > 5 && i++ < var.rb_cnt)
				rrb(info);
			hard_sort(info, var.pa_cnt, 'a');
			hard_sort(info, size - var.pa_cnt, 'b');
		}
	}
}
