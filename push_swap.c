#include "push_swap.h"

// int	argv_len(char **argv)
// {
// 	int	i;

// 	i = 0;
// 	while (argv[i])
// 		i++;
// 	return (i);
// }

// void	error(int n)
// {
// 	if (n > 0)
// 	{
// 		write(1, "Error\n", 6);
// 		exit(1);
// 	}
// }

// int	get_argv_size(char **argv)
// {
// 	int	size;

// 	size = 0;
// 	while (argv[size])
// 		size++;
// 	return (size);
// }

// void	check_error(int	*arr, int argv_size, char **argv)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < argv_size)
// 	{
// 		j = 0;
// 		while (argv[i][j])
// 		{
// 			if (!ft_isdigit(argv[i][j++]))
// 				error(1);
// 		}
// 		arr[i] = ft_atoll(argv[i]);
// 		if (arr[i] > INT_MAX || arr[i] < INT_MIN)
// 			error(1);
// 		j = 0;
// 		while (j < i)
// 		{
// 			if (arr[i] == arr[j++])
// 				error(1);
// 		}
// 		i++;
// 	}
// }

void add_to_stack_a(char *arr, t_info *info)
{
	t_node *temp;

	temp = malloc(sizeof(t_node));
	temp->content = ft_atoll(arr);
	printf("%d\n", temp->content);
	temp->next = NULL;
	temp->prev = NULL;
	if (info->a_size > 0)
	{
		info->a_top->next = temp;
		temp->prev = info->a_top;
		info->a_bottom = temp;
	}
	else
	{
		info->a_top = temp;
		info->a_bottom = temp;
	}
	info->a_size++;
}

void a_to_b(int size, int size_i, t_info *info, t_info *sorted_list)
{
	int i;
	int pivot;
	int ra_count;
	if (size <= 1)
	{
		return;
	} //최적화 정렬
	pivot = select_pivot(size / 2 + size_i, sorted_list);
	i = 0;
	ra_count = 0;
	while (i < size)
	{
		if (info->a_top->content > pivot)
		{
			ra(info);
			ra_count++;
		}
		else
			pb(info);
		i++;
	}
	i = 0;
	while (i < ra_count)
	{
		rra(info);
		i++;
	}
	a_to_b(ra_count, size_i, info, sorted_list);
	b_to_a(size - ra_count, size_i + ra_count, info, sorted_list);
}

void b_to_a(int size, int size_i, t_info *info, t_info *sorted_list)
{
	int i;
	int pivot;
	int pa_count;

	pivot = select_pivot(size / 2 + size_i, sorted_list);
	if (size <= 1)
	{
		pa(info);
		return;
	}
	i = 0;
	pa_count = 0;
	while (i < size)
	{
		if (info->b_top->content > pivot)
		{
			pa(info);
			pa_count++;
		}
		else
		{
			rb(info);
		}
		i++;
	}
	i = 0;
	while (i < size - pa_count)
	{
		rrb(info);
		i++;
	}
	a_to_b(pa_count, size_i, info, sorted_list);
	b_to_a(size - pa_count, size_i + pa_count, info, sorted_list);
}

void init_info(t_info *info)
{
	info->a_size = 0;
	info->b_size = 0;
	info->a_top = NULL;
	info->a_bottom = NULL;
	info->b_top = NULL;
	info->b_bottom = NULL;
}

int main(int argc, char **argv)
{
	int i;
	int j;
	int count;
	char **arr;
	t_info info;
	t_info sorted_list;

	init_info(&info);
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
			add_to_stack_a(arr[j], &info);
			add_to_stack_a(arr[j], &sorted_list);
			count++;
			j++;
		}
		i++;
	}

	sort(&sorted_list);
	a_to_b(info.a_size, 0, &info, &sorted_list);
	i = 0;
	while (i < info.a_size)
	{
		printf("%d ", info.a_bottom->content);
		info.a_bottom = info.a_bottom->next;
		i++;
	}
	printf("\n");
	// while (1)
	// {
	// 	scanf("%s", cmd);
	// 	if (ft_strcmp(*cmd, "pa"))
	// 		pa(info);
	// 	else if (ft_strcmp(*cmd, "pb"))
	// 		pb(info);
	// 	else if (ft_strcmp(*cmd, "sa"))
	// 		sa(info);
	// 	else if (ft_strcmp(*cmd, "sb"))
	// 		sb(info);
	// 	else if (ft_strcmp(*cmd, "ss"))
	// 		ss(info);
	// 	else if (ft_strcmp(*cmd, "ra"))
	// 		ra(info);
	// 	else if (ft_strcmp(*cmd, "rb"))
	// 		rb(info);
	// 	else if (ft_strcmp(*cmd, "rr"))
	// 		rr(info);
	// 	else if (ft_strcmp(*cmd, "rra"))
	// 		rra(info);
	// 	else if (ft_strcmp(*cmd, "rrb"))
	// 		rrb(info);
	// 	else if (ft_strcmp(*cmd, "rrr"))
	// 		rrr(info);
	// }
	// 	int	i;
	// 	int	*arr;
	// 	int	argv_size;

	// 	i = 0;
	// 	argv = ft_split(argv[1], ' ');
	// 	argv_size = get_argv_size(argv);
	// 	printf("----\n");
	// 	arr = (int *)malloc(argv_size * sizeof(int));
	// 	check_error(arr, argv_size, argv);
	// 	printf("-----\n");
	// 	i = 0;
	// 	while (arr[i])
	// 		printf("%d ", arr[i++]);
	// 	printf("\n");
}