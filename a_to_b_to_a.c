#include "push_swap.h"

void	reverse(t_info *info, t_var *var)
{
	int	i;

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

void	a_b_cmd(t_info *info, t_var *var, int r)
{
	if (info->a_top->content >= var->l_pivot)
	{
		if (info->a_size == 2 && info->a_top->next->content < var->l_pivot)
		{
			sa(info);
			pb(info);
			var->pb_cnt++;
		}
		else if (!is_sorted(info, r - var->ra_cnt - var->pb_cnt, var->l_pivot))
		{
			ra(info);
			var->ra_cnt++;
		}
	}
	else
	{
		pb(info);
		var->pb_cnt++;
		if (info->b_top->content >= var->s_pivot)
		{
			rb(info);
			var->rb_cnt++;
		}
	}
}

void	b_a_cmd(t_info *info, t_var *var, int r)
{
	if (info->b_top->content < var->s_pivot)
	{
		if (info->b_size == 2 && info->b_top->next->content >= var->l_pivot)
		{
			sb(info);
			pa(info);
			var->pa_cnt++;
		}
		else if (!is_rsorted(info, r - var->rb_cnt - var->pa_cnt, var->s_pivot))
		{
			rb(info);
			var->rb_cnt++;
		}
	}
	else
	{
		pa(info);
		var->pa_cnt++;
		if (info->a_top->content < var->l_pivot)
		{
			ra(info);
			var->ra_cnt++;
		}
	}
}

void	a_to_b(t_info *info, int r)
{
	int		i;
	t_var	var;

	init_var(&var);
	if (r <= 5)
	{
		hard_sort(info, r, 'a');
		return ;
	}
	select_pivot(info->a_top, r, &var.s_pivot, &var.l_pivot);
	i = 0;
	while (i++ < r)
		a_b_cmd(info, &var, r);
	reverse(info, &var);
	a_to_b(info, r - var.pb_cnt);
	b_to_a(info, var.rb_cnt);
	b_to_a(info, var.pb_cnt - var.rb_cnt);
}

void	b_to_a(t_info *info, int r)
{
	int		i;
	t_var	var;

	i = 0;
	if (r <= 5)
	{
		if (r == 1)
			pa(info);
		else
			hard_sort(info, r, 'b');
		return ;
	}
	select_pivot(info->b_top, r, &var.s_pivot, &var.l_pivot);
	i = 0;
	init_var(&var);
	while (i++ < r)
		b_a_cmd(info, &var, r);
	a_to_b(info, var.pa_cnt - var.ra_cnt);
	reverse(info, &var);
	a_to_b(info, var.ra_cnt);
	b_to_a(info, r - var.pa_cnt);
}
