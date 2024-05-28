/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:42:55 by changhle          #+#    #+#             */
/*   Updated: 2022/10/10 18:42:56 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parser.h"
#include "libft.h"

t_parsed_list	*add_node(t_parsed_list **node)
{
	t_parsed_list	*new;
	t_parsed_list	*tmp;

	tmp = *node;
	new = ft_malloc(sizeof(t_parsed_list));
	new->parsed_unit = ft_malloc(sizeof(t_parsed_unit));
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
	tmp[n] = NULL;
	if (token)
		tmp[n] = ft_strdup(token);
	tmp[n + 1] = NULL;
	node->cmd = tmp;
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

static void	add_null_cmd(t_parsed_list **parsed_head)
{
	t_parsed_list	*node;

	node = *parsed_head;
	while (node)
	{
		if (!node->parsed_unit->cmd
			&& (node->parsed_unit->redir_in_list
				|| node->parsed_unit->redir_out_list))
		{
			node->parsed_unit->cmd = ft_malloc(sizeof(char *));
			node->parsed_unit->cmd[0] = NULL;
		}
		node = node->next;
	}
}

void	mini_parse(t_token_list *token, t_parsed_list **parsed_head)
{
	t_parsed_list	*node;

	if (token)
		node = add_node(parsed_head);
	while (token)
	{
		if (token->token_type == WORD)
			add_cmd(node->parsed_unit, token->token);
		else if (token->token_type == REDIRECT)
		{
			add_redirect(node->parsed_unit, token);
			token = token->next;
			if (!token)
				break ;
		}
		else if (token->token_type == PIPE)
			node = add_node(parsed_head);
		token = token->next;
	}
	add_null_cmd(parsed_head);
}
