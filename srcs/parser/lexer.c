#include <stdio.h>
#include <unistd.h>

#include "minishell.h"
#include "parser.h"
#include "libft.h"

static int	syntax_error(char *str)
{
	ft_putstr_fd("minishell: syntax error near unexpected token `",
		STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd("\'\n", STDERR_FILENO);
	g_exit_status = 258;
	return (1);
}

int	lexer(t_token_list **head)
{
	t_token_list	*token;

	token = *head;
	if (!token)
		return (FAILURE);
	while (token)
	{
		if (token->token_type != WORD && !token->next)
			return (syntax_error("newline"));
		else if ((token->token_type == REDIRECT
				&& token->next->token_type != WORD)
			|| (token->token_type == PIPE && token->next->token_type == PIPE))
			return (syntax_error(token->next->token));
		token = token->next;
	}
	return (SUCCESS);
}
