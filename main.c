/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 11:56:13 by changhle          #+#    #+#             */
/*   Updated: 2022/06/19 19:07:42 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static void	free_all(t_info *info)
{
	t_node	*temp;

	while (info->a_top)
	{
		temp = info->a_top;
		info->a_top = temp->next;
		free(temp);
		temp = NULL;
	}
	while (info->cmd_top)
	{
		temp = info->cmd_top;
		info->cmd_top = temp->next;
		free(temp);
		temp = NULL;
	}
	free(info);
}

static void	fill_stack(t_info *info, char **argv)
{
	int		i;
	int		j;
	char	**arr;

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
}

int	main(int argc, char **argv)
{
	t_info	*info;
	t_node	*temp;

	info = malloc(sizeof(t_info));
	if (!info)
		return (0);
	init_info(info);
	if (argc < 2)
		return (0);
	fill_stack(info, argv);
	if (info->a_size == 5)
		sort_5(info);
	else
		a_to_b(info, info->a_size);
	optimize(info);
	temp = info->cmd_top;
	while (temp)
	{
		write(1, temp->command, ft_strlen(temp->command));
		write(1, "\n", 1);
		temp = temp->next;
	}
	free_all(info);
	return (0);
}
