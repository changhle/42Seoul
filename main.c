#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	char	**arr;
	t_info	*info;
	t_node	*temp;

	info = malloc(sizeof(t_info));
	init_info(info);
	if (argc < 2)
		return (0);
	i = 1;
	while (argv[i])
	{
		arr = ft_split(argv[i], ' ');
		j = 0;
		while (arr[j])
		{
			push_to_stack_a(arr[j], info);
			j++;
		}
		i++;
	}
	a_to_b(info, info->a_size);
	optimize(info);
	while (info->a_top)
	{
		temp = info->a_top;
		info->a_top = temp->next;
		free(temp);
		temp = NULL;
	}
	temp = info->cmd_top;
	while (temp)
	{
		write(1, temp->command, ft_strlen(temp->command));
		write(1, "\n", 1);
		temp = temp->next;
	}
}
