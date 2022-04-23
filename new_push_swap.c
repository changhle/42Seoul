#include "new_push_swap.h"

void init_info(t_info *info)
{
	info->a_size = 0;
	info->b_size = 0;
	info->cmd = 0;
	info->a_top = NULL;
	info->a_bottom = NULL;
	info->b_top = NULL;
	info->b_bottom = NULL;
}

void push_to_stack_a(char *arr, t_info *info)
{
	t_node *temp;

	temp = malloc(sizeof(t_node));
	temp->content = ft_atoll(arr);
	// printf("%d\n", temp->content);
	temp->next = NULL;
	temp->prev = NULL;
	if (info->a_size > 0)
	{
		info->a_bottom->next = temp;
		temp->prev = info->a_bottom;
		info->a_bottom = temp;
	}
	else
	{
		info->a_top = temp;
		info->a_bottom = temp;
	}
	info->a_size++;
}

void a_to_b(t_info *info, int r)
{
	// printf("a----->b | r = %d\n", r);
	int i;
	int tmp;
	int ra_cnt;
	int rb_cnt;
	int pb_cnt;
	int l_pivot;
	int s_pivot;

	if (is_sorted(info, r))
		return;
	if (r <= 6)
	{
		hard_sort(info, r, 'a');
		// printf("(-------------------hard_sort---------------------)\n");
		return;
	} // hard sorting!!
	select_pivot(info, r, &s_pivot, &l_pivot, 'a');
	i = 0;
	ra_cnt = 0;
	rb_cnt = 0;
	pb_cnt = 0;
	while (i < r)
	{
		if (info->a_top->content >= l_pivot)
		{
			if (!is_sorted(info, r - ra_cnt))
			{
				ra(info);
				ra_cnt++;
			}
		}
		else
		{
			tmp = info->a_top->content;
			pb(info);
			pb_cnt++;
			if (tmp >= s_pivot)
			{
				rb(info);
				rb_cnt++;
			}
		}
		i++;
	}
	i = 0;
	while (i < ra_cnt && i < rb_cnt)
	{
		rrr(info);
		i++;
	}
	while (i++ < ra_cnt)
		rra(info);
	while (i++ < rb_cnt)
		rrb(info);
	a_to_b(info, ra_cnt);
	b_to_a(info, rb_cnt);
	b_to_a(info, pb_cnt - rb_cnt);
	// printf("(----------------------------------------)\n");
}

void b_to_a(t_info *info, int r)
{
	// printf("b----->a | r = %d\n", r);
	int i;
	int tmp;
	int ra_cnt;
	int rb_cnt;
	int pa_cnt;
	int l_pivot;
	int s_pivot;

	i = 0;
	if (is_rsorted(info, r))
	{
		while (i++ < r)
			pa(info);
		return;
	}
	if (r <= 6)
	{
		if (r == 1)

			pa(info);
		else
			hard_sort(info, r, 'b');
		// pa(info);
		// printf("(-------------------hard_sort---------------------)\n");
		return;
	} // hard sorting!!
	select_pivot(info, r, &s_pivot, &l_pivot, 'b');
	i = 0;
	ra_cnt = 0;
	rb_cnt = 0;
	pa_cnt = 0;
	while (i < r)
	{
		if (info->b_top->content < s_pivot)
		{
			rb(info);
			rb_cnt++;
		}
		else
		{
			tmp = info->b_top->content;
			pa(info);
			pa_cnt++;
			if (tmp < l_pivot)
			{
				ra(info);
				ra_cnt++;
			}
		}
		i++;
	}
	a_to_b(info, pa_cnt - ra_cnt);
	i = 0;
	while (i < ra_cnt && i < rb_cnt)
	{
		rrr(info);
		i++;
	}
	while (i++ < ra_cnt)
		rra(info);
	while (i++ < rb_cnt)
		rrb(info);
	a_to_b(info, ra_cnt);
	b_to_a(info, rb_cnt);
	// printf("(----------------------------------------)\n");
}

int main(int argc, char **argv)
{
	int i;
	int j;
	int count;
	char **arr;
	t_info *info;
	t_info *s_list;
	t_node *temp;

	info = malloc(sizeof(t_info));
	s_list = malloc(sizeof(t_info));
	init_info(info);
	init_info(s_list);
	if (argc < 2)
		return (0);
	i = 1;
	count = 0;
	while (argv[i])
	{
		arr = ft_split(argv[i], ' ');
		j = 0;
		while (arr[j])
		{
			push_to_stack_a(arr[j], info);
			push_to_stack_a(arr[j], s_list);
			count++;
			j++;
		}
		i++;
	}
	sort(s_list);
	a_to_b(info, info->a_size);
	// i = 0;
	// temp = info->a_top;
	// while (i < info->a_size)
	// {
	// 	printf("%d ", temp->content);
	// 	temp = temp->next;
	// 	i++;
	// }
	// printf("\ncmd : %d\n", info->cmd);
}