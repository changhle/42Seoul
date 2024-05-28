/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:43:00 by changhle          #+#    #+#             */
/*   Updated: 2022/10/11 11:18:09 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "minishell.h"
#include "parser.h"
#include "libft.h"

static int	print_error(char c)
{
	if (c == '\'' || c == '\"')
		ft_putstr_fd("minishell: syntax error near unclosed quote `",
			STDERR_FILENO);
	else
		ft_putstr_fd("minishell: syntax error near unexpected char `",
			STDERR_FILENO);
	ft_putchar_fd(c, STDERR_FILENO);
	ft_putstr_fd("\'\n", STDERR_FILENO);
	g_exit_status = 1;
	return (1);
}

static int	not_interpret(char *line)
{
	char	quote;

	quote = 0;
	while (*line)
	{
		if (*line == '\'' || *line == '\"')
			quote = set_quote(quote, *line);
		else if (quote == 0 && (*line == '\\' || *line == ';'))
			return (print_error(*line));
		line++;
	}
	if (quote != 0)
		return (print_error(quote));
	return (0);
}

void	free_token_list(t_token_list *token_list)
{
	t_token_list	*tmp;

	while (token_list)
	{
		tmp = NULL;
		if (token_list->next)
			tmp = token_list->next;
		ft_free((void **)&token_list->token);
		ft_free((void **)&token_list);
		token_list = tmp;
	}
}

int	parse(char *line, t_parsed_list **parsed_head, t_env_list **env_list)
{
	t_token_list	*token_head;
	int				ret_value;

	*parsed_head = NULL;
	if (not_interpret(line))
		return (FAILURE);
	token_head = NULL;
	tokenizer(line, &token_head);
	ret_value = lexer(&token_head);
	if (ret_value == FAILURE)
	{
		free_token_list(token_head);
		return (ret_value);
	}
	expander(&token_head, env_list);
	*parsed_head = NULL;
	mini_parse(token_head, parsed_head);
	free_token_list(token_head);
	return (ret_value);
}
