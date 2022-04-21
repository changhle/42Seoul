#include "new_push_swap.h"

void a_3(t_info *info)
{
	int a, b, c;

	c = info->a_top->content;
	b = info->a_top->next->content;
	a = info->a_top->next->next->content;
	// if (c < b && b < a)
	// 	return;
	if ((a < b && b < c) || (b < a && a < c))
		sa(info);
	if (((a < b) && (c < a || b < c)) || (a < c && (c < b || b < a)))
	{
		ra(info);
		sa(info);
		rra(info);
	}
	if ((a < b && b < c) || (a < c && c < b))
		sa(info);
}

void b_3(t_info *info)
{
	int a, b, c;

	c = info->b_top->content;
	b = info->b_top->next->content;
	a = info->b_top->next->next->content;
	if ((c < b && b < a) || (c < a && a < b) || (a < c && c < b))
		sb(info);
	if ((b < a && (c < b || a < b)))
	{
		rb(info);
		sb(info);
		pa(info);
		rrb(info);
	}
	if ((c < a && (a < b || b < c)))
	{
		pa(info);
		sb(info);
	}
	if (a < b && b < c)
		pa(info);
	pa(info);
}

void a_2(t_info *info)
{
	int a, b;

	b = info->a_top->content;
	a = info->a_top->next->content;
	if (a < b)
		sa(info);
}

void b_2(t_info *info)
{
	int a, b;

	b = info->b_top->content;
	a = info->b_top->next->content;
	if (a > b)
		sb(info);
	pa(info);
}

void hard_sort(t_info *info, int size, char stack)
{
	if (stack == 'a')
	{
		if (size == 3)
			a_3(info);
		else if (size == 2)
			a_2(info);
	}
	else if (stack == 'b')
	{
		if (size == 3)
			b_3(info);
		else if (size == 2)
			b_2(info);
	}
}