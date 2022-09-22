#include <stdio.h>
#include <stdlib.h>

#include "minishell.h"
#include "parser.h"
#include "libft.h"

t_parsed_list	*add_node(t_parsed_list **node)
{
	t_parsed_list	*new;
	t_parsed_list	*tmp;

	tmp = *node;
	new = malloc(sizeof(t_parsed_list));
	new->parsed_unit = malloc(sizeof(t_parsed_unit));
	new->parsed_unit->cmd = NULL;
	new->parsed_unit->redir_in_list = NULL;
	new->parsed_unit->redir_out_list = NULL;
	new->next = NULL;
	if (!(*node))
		*node = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (new);
}

void	add_node_cmd(t_parsed_unit *node, char *token)
{
	int	n;
	char	**tmp;

	n = 0;
	if (!node->cmd)
		tmp = ft_malloc(sizeof(char *) * 2);
	else
	{
		while (node->cmd[n])
			n++;
		tmp = ft_malloc(sizeof(char *) * (n + 2));
		n = 0;
		while (node->cmd[n])
		{
			tmp[n] = node->cmd[n];
			n++;
		}
	}
	tmp[n] = ft_strdup(token);
	tmp[n + 1] = NULL;
	// free(node->cmd);
	node->cmd = tmp;
	n = 0;
}
int	mini_parse(t_token_list *token, t_parsed_list **parsed_head)
{
	int	ret_value;
	t_parsed_list	*node;

	ret_value = 0; ///////////// temp
	if (token)
		node = add_node(parsed_head);
	while (token)
	{
		if (token->token_type == WORD)
			add_node_cmd(node->parsed_unit, token->token);
		// else if (token->token_type == REDIRECT)
		// 	add_node_redirect(node);
		else if (token->token_type == PIPE)
			node = add_node(parsed_head);
		token = token->next;
	}
	(void) parsed_head; ///////////// temp
	return (ret_value);
}
