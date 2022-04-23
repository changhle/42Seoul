#include "new_push_swap.h"

void a_3(t_info *info)
{
	int a, b, c;

	a = info->a_top->content;
	b = info->a_top->next->content;
	c = info->a_top->next->next->content;
	// if (c < b && b < a)
	// 	return;
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

void b_3(t_info *info)
{
	int a, b, c;

	a = info->b_top->content;
	b = info->b_top->next->content;
	c = info->b_top->next->next->content;

	if ((a < b && (b < c || c < a)) || (a < c && c < b))
		sb(info);
	if ((a < b && b < c) || (b < a && a < c))
	{
		rb(info);
		sb(info);
		pa(info);
		rrb(info);
	}
	if ((a < c && c < b) || (b < c && c < a))
	{
		pa(info);
		sb(info);
	}
	if ((c < b && b < a) || (c < a && a < b))
		pa(info);
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
	pa(info);
}

void select_mid_pivot(t_info *info, int r, int *pivot, char stack)
{
	int i;
	int *arr;
	t_node *temp;

	arr = malloc(sizeof(int) * (r + 1));
	i = 0;
	if (stack == 'a')
		temp = info->a_top;
	else
		temp = info->b_top;
	while (i < r)
	{
		arr[i] = temp->content;
		temp = temp->next;
		i++;
	}
	sort_arr(arr, r);
	*pivot = arr[r / 2];
	free(arr);
}

void hard_sort(t_info *info, int size, char stack)
{
	int i;
	int pivot;
	int ra_cnt;
	int rb_cnt;
	int pa_cnt;
	int pb_cnt;

	ra_cnt = 0;
	rb_cnt = 0;
	pa_cnt = 0;
	pb_cnt = 0;
	if (stack == 'a')
	{
		// if (size > 3)
		// {
		// 	pb(info);
		// 	pb(info);
		// 	hard_sort(info, size - 2, 'a');
		// 	hard_sort(info, 2, 'b');
		// }
		if (size == 3)
			a_3(info);
		else if (size == 2)
			a_2(info);
		else
		{
			select_mid_pivot(info, size, &pivot, 'a');
			while (pb_cnt < size / 2)
			{
				if (info->a_top->content >= pivot)
				{
					ra(info);
					ra_cnt++;
				}
				else
				{
					pb(info);
					pb_cnt++;
				}
			}
			i = 0;
			while (i++ < ra_cnt)
				rra(info);
			hard_sort(info, size - pb_cnt, 'a');
			hard_sort(info, pb_cnt, 'b');
		}
	}
	else if (stack == 'b')
	{
		// if (size > 3)
		// {
		// 	pa(info);
		// 	pa(info);
		// 	pa(info);
		// 	hard_sort(info, 3, 'a');
		// 	hard_sort(info, size - 3, 'b');
		// }
		if (size == 3)
			b_3(info);
		else if (size == 2)
			b_2(info);
		else
		{
			select_mid_pivot(info, size, &pivot, 'b');
			while (pa_cnt < (size + 1) / 2)
			{
				if (info->b_top->content < pivot)
				{
					rb(info);
					rb_cnt++;
				}
				else
				{
					pa(info);
					pa_cnt++;
				}
			}
			i = 0;
			while (i++ < rb_cnt)
				rrb(info);
			hard_sort(info, size - pa_cnt, 'a');
			hard_sort(info, pa_cnt, 'b');
		}
	}
}