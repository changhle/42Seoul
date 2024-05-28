/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_parser_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:42:51 by changhle          #+#    #+#             */
/*   Updated: 2022/10/10 18:42:52 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include "minishell.h"
#include "parser.h"
#include "libft.h"

void	add_redirect_node(t_redirect_list **head,
	t_token_list *token, t_redirect_type type)
{
	t_redirect_list	*new;
	t_redirect_list	*tmp;

	tmp = *head;
	new = ft_malloc(sizeof(t_redirect_list));
	new->redir_type = type;
	new->filename = NULL;
	if (token->next->token && token->next->token_type == WORD)
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

void	free_old_cmd(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
		free(cmd[i++]);
	free(cmd);
}
