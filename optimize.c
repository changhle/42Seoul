/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 07:22:02 by changhle          #+#    #+#             */
/*   Updated: 2022/06/19 19:21:10 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*remove_node(t_node *node)
{
	t_node	*temp;

	temp = node;
	if (!node->prev)
	{
		node = node->next->next;
		node->prev = node;
	}
	else
	{
		node = node->prev;
		node->next = node->next->next;
		node->next = node->next->next;
		node->next->prev = node;
	}
	free(temp->next);
	free(temp);
	return (node);
}

t_node	*replace_node(t_node *node, char *cmd)
{
	t_node	*temp;

	temp = node;
	if (!node->prev)
	{
		node = node->next;
		node->prev = NULL;
		node->command = cmd;
	}
	else
	{
		node = node->prev;
		node->next = node->next->next;
		node->next->prev = node;
		node->next->command = cmd;
	}
	free(temp);
	return (node);
}

void	optimize(t_info *info)
{
	t_node	*temp;
	char	*s1;
	char	*s2;

	temp = info->cmd_top;
	while (temp->next)
	{
		s1 = temp->command;
		s2 = temp->next->command;
		if ((!ft_strcmp(s1, "pa") && !ft_strcmp(s2, "pb"))
			|| (!ft_strcmp(s1, "pb") && !ft_strcmp(s2, "pa"))
			|| (!ft_strcmp(s1, "ra") && !ft_strcmp(s2, "rra"))
			|| (!ft_strcmp(s1, "rra") && !ft_strcmp(s2, "ra"))
			|| (!ft_strcmp(s1, "rb") && !ft_strcmp(s2, "rrb"))
			|| (!ft_strcmp(s1, "rrb") && !ft_strcmp(s2, "rb"))
			|| (!ft_strcmp(s1, "rr") && !ft_strcmp(s2, "rrr"))
			|| (!ft_strcmp(s1, "rrr") && !ft_strcmp(s2, "rr")))
			temp = remove_node(temp);
		else if ((!ft_strcmp(s1, "ra") && !ft_strcmp(s2, "rb"))
			|| (!ft_strcmp(s1, "rb") && !ft_strcmp(s2, "ra")))
			temp = replace_node(temp, "rr");
		else if ((!ft_strcmp(s1, "rra") && !ft_strcmp(s2, "rrb"))
			|| (!ft_strcmp(s1, "rrb") && !ft_strcmp(s2, "rra")))
			temp = replace_node(temp, "rrr");
		else if ((!ft_strcmp(s1, "sa") && !ft_strcmp(s2, "sb"))
			|| (!ft_strcmp(s1, "sb") && !ft_strcmp(s2, "sa")))
			temp = replace_node(temp, "ss");
		else
			temp = temp->next;
	}
}
