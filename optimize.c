/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 07:22:02 by changhle          #+#    #+#             */
/*   Updated: 2022/06/19 09:23:26 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *str1, char *str2)
{
	while ((*str1 && *str2) && (*str1 == *str2))
	{
		str1++;
		str2++;
	}
	return (*(unsigned char *)str1 - *(unsigned char *)str2);
}

t_node	*remove_node(t_node *node)
{
	t_node	*temp;

	temp = node;
	if (!node->prev)
		node = temp->next->next;
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
			|| (!ft_strcmp(s1, "rrb") && !ft_strcmp(s2, "rb")))
			temp = remove_node(temp);
		else
			temp = temp->next;
	}
}
