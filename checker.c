#include "push_swap.h"

void	check_sort(t_node *node)
{
	while (node->next)
	{
		if (node->content > node->next->content)
		{
			write(1, "KO\n", 3);
			return ;
		}
		node = node->next;
	}
	write(1, "OK\n", 3);
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	char	**arr;
	char	buf[3];
	char	c;
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
	i = 0;
	while (read(0, &c, 1))
	{
		if (c != '\n')
		{
			buf[i] = c;
			i++;
		}
		else
		{
			// write(1, buf, 3);
			// write(1, "\n", 1);
			// printf("-%s-\n", buf);
			operation(info, buf, 1);
			i = 0;
		}
	}
	operation(info, buf, 1);
	// buf = get_next_line(0);
	// while (buf)
	// {
	// 	i = 0;
	// 	printf("%s\n", buf);
	// 	// while (buf[i])
	// 	// {
	// 	// 	if (buf[i] == '\n')
	// 	// 		buf[i] = '\0';
	// 	// 	i++;
	// 	// }
	// 	operation(info, buf, 1);
	// 	buf = get_next_line(0);
	// 	printf("%s\n", buf);
	// }
	// temp = info->a_top;
	// while (temp)
	// {
	// 	printf("%d ", temp->content);
	// 	// printf("%s\n", temp->command);
	// 	temp = temp->next;
	// }
	check_sort(info->a_top);
}