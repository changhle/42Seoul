#include "push_swap.h"

void	init_var(t_var *var)
{
	var->ra_cnt = 0;
	var->rb_cnt = 0;
	var->pa_cnt = 0;
	var->pb_cnt = 0;
}

void	init_info(t_info *info)
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

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	int		count;
	char	**arr;
	t_info	*info;
	t_info	*s_list;
	t_node	*temp;

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
			// push_to_stack_a(arr[j], s_list);
			count++;
			j++;
		}
		i++;
	}
	// sort(s_list);
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