#include "new_push_swap.h"

void init_var(t_var *var)
{
	var->ra_cnt = 0;
	var->rb_cnt = 0;
	var->pa_cnt = 0;
	var->pb_cnt = 0;
}

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

void push_to_stack_command(t_info *info, char *str)
{
	t_node *temp;

	temp = malloc(sizeof(t_node));
	temp->command = str;
	temp->next = NULL;
	temp->prev = NULL;
	if (info->cmd_top)
	{
		info->cmd_bottom->next = temp;
		temp->prev = info->cmd_bottom;
		info->cmd_bottom = temp;
	}
	else
	{
		info->cmd_top = temp;
		info->cmd_bottom = temp;
	}
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

void reverse(t_info *info, t_var *var)
{
	int i;

	i = 0;
	while (i < var->ra_cnt && i < var->rb_cnt)
	{
		rrr(info);
		i++;
	}
	while (i < var->ra_cnt)
	{
		rra(info);
		i++;
	}
	while (i < var->rb_cnt)
	{
		rrb(info);
		i++;
	}
}

void a_to_b(t_info *info, int r)
{
	// printf("a----->b | r = %d\n", r);
	int i;
	t_var var;

	init_var(&var);
	if (r <= 5)
	{
		hard_sort(info, r, 'a');
		// printf("(-------------------hard_sort---------------------)\n");
		return;
	} // hard sorting!!
	select_pivot(info, r, &var.s_pivot, &var.l_pivot, 'a');
	i = 0;
	while (i++ < r)
	{
		if (info->a_top->content >= var.l_pivot)
		{
			if (info->a_size == 2 && info->a_top->next->content < var.l_pivot)
			{
				sa(info);
				pb(info);
				var.pb_cnt++;
			}
			else if (!is_sorted(info, r - var.ra_cnt - var.pb_cnt, var.l_pivot))
			{
				ra(info);
				var.ra_cnt++;
			}
		}
		else
		{
			pb(info);
			var.pb_cnt++;
			if (info->b_top->content >= var.s_pivot)
			{
				rb(info);
				var.rb_cnt++;
			}
		}
	}
	reverse(info, &var);
	a_to_b(info, r - var.pb_cnt);
	b_to_a(info, var.rb_cnt);
	b_to_a(info, var.pb_cnt - var.rb_cnt);
	// printf("(----------------------------------------)\n");
}

void b_to_a(t_info *info, int r)
{
	// printf("b----->a | r = %d\n", r);
	int i;
	t_var var;

	i = 0;
	if (r <= 5)
	{
		if (r == 1)
			pa(info);
		else
			hard_sort(info, r, 'b');
		// printf("(-------------------hard_sort---------------------)\n");
		return;
	} // hard sorting!!
	select_pivot(info, r, &var.s_pivot, &var.l_pivot, 'b');
	i = 0;
	init_var(&var);
	while (i++ < r)
	{
		if (info->b_top->content < var.s_pivot)
		{
			if (info->b_size == 2 && info->b_top->next->content >= var.l_pivot)
			{
				sb(info);
				pa(info);
				var.pa_cnt++;
			}
			else if (!is_rsorted(info, r - var.rb_cnt - var.pa_cnt, var.s_pivot))
			{
				rb(info);
				var.rb_cnt++;
			}
		}
		else
		{
			pa(info);
			var.pa_cnt++;
			if (info->a_top->content < var.l_pivot)
			{
				ra(info);
				var.ra_cnt++;
			}
		}
	}
	a_to_b(info, var.pa_cnt - var.ra_cnt);
	reverse(info, &var);
	a_to_b(info, var.ra_cnt);
	b_to_a(info, r - var.pa_cnt);
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
	// if (info->a_size <= 5)
	// 	hard_sort(info, info->a_size, 'a')
	a_to_b(info, info->a_size);
	temp = info->cmd_top;
	while (temp)
	{
		printf("%s", temp->command);
		temp = temp->next;
	}
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