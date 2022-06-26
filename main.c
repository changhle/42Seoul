/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 11:56:13 by changhle          #+#    #+#             */
/*   Updated: 2022/06/26 16:38:37 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <unistd.h>

static void	print_command(t_node *temp)
{
	while (temp)
	{
		write(1, temp->command, ft_strlen(temp->command));
		write(1, "\n", 1);
		temp = temp->next;
	}
}

static void	check_argv(char **argv)
{
	int	i;
	int	j;
	int	flag;

	i = 1;
	flag = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]))
				flag = 1;
			j++;
		}
		if (flag == 0)
			print_error(1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_info	*info;
	t_node	*temp;

	if (argc < 2)
		return (0);
	info = malloc(sizeof(t_info));
	if (!info)
		print_error(2);
	init_info(info);
	check_argv(argv);
	fill_stack(info, argv);
	check_overlap(info);
	if (info->a_size == 3 || info->a_size == 5)
		sort_3_5(info);
	else
		a_to_b(info, info->a_size);
	if (info->a_size >= 5)
		optimize(info);
	print_command(info->cmd_top);
	free_all(info);
	return (0);
}
