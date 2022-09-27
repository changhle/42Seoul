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

void	free_old_cmd(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
		free(cmd[i++]);
	free(cmd);
}

void	add_cmd(t_parsed_unit *node, char *token)
{
	int		n;
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
			tmp[n] = ft_strdup(node->cmd[n]);
			n++;
		}
		free_old_cmd(node->cmd);
	}
	tmp[n] = ft_strdup(token);
	tmp[n + 1] = NULL;
	node->cmd = tmp;
}

void	add_redirect_node(t_redirect_list **head,
	t_token_list *token, t_redirect_type type)
{
	t_redirect_list	*new;
	t_redirect_list	*tmp;

	tmp = *head;
	new = ft_malloc(sizeof(t_redirect_list));
	new->redir_type = type;
	new->filename = ft_strdup(token->next->token);
	new->next = NULL;
	if (!tmp)
		*head = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	add_redirect(t_parsed_unit *node, t_token_list *token)
{
	t_redirect_type	type;
	t_redirect_list	*tmp;

	type = is_redirect(token->token);
	if (type == REDIR_IN || type == REDIR_IN_APPEND)
		tmp = node->redir_in_list;
	else
		tmp = node->redir_out_list;
	add_redirect_node(&tmp, token, type);
	if (type == REDIR_IN || type == REDIR_IN_APPEND)
		node->redir_in_list = tmp;
	else
		node->redir_out_list = tmp;
}

int	mini_parse(t_token_list *token, t_parsed_list **parsed_head)
{
	int				ret_value;
	t_parsed_list	*node;

	ret_value = 0; ///////////// temp
	if (token)
		node = add_node(parsed_head);
	while (token)
	{
		if (token->token_type == WORD)
			add_cmd(node->parsed_unit, token->token);
		else if (token->token_type == REDIRECT)
		{
			if (token->next->token_type == WORD)
				add_redirect(node->parsed_unit, token);
			token = token->next;
		}
		else if (token->token_type == PIPE)
			node = add_node(parsed_head);
		token = token->next;
	}
	return (ret_value);
}
