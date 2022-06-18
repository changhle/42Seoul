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
		node->next = node->next->next->next;
	}
	free(temp->next);
	free(temp);
	return (node);
}

void	optimize(t_info *info)
{
	t_node	*temp;

	temp = info->cmd_top;
	while (temp->next)
	{
		if ((!ft_strcmp(temp->command, "pa") && !ft_strcmp(temp->next->command, "pb")) ||
			(!ft_strcmp(temp->command, "pb") && !ft_strcmp(temp->next->command, "pa")) ||
			(!ft_strcmp(temp->command, "ra") && !ft_strcmp(temp->next->command, "rra")) ||
			(!ft_strcmp(temp->command, "rra") && !ft_strcmp(temp->next->command, "ra")) ||
			(!ft_strcmp(temp->command, "rb") && !ft_strcmp(temp->next->command, "rrb")) ||
			(!ft_strcmp(temp->command, "rrb") && !ft_strcmp(temp->next->command, "rb")))
			temp = remove_node(temp);
		else
			temp = temp->next;
	}
}