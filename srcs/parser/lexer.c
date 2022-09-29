#include <stdio.h>

#include "minishell.h"
#include "parser.h"
#include "libft.h"

static int	syntax_error(char *str)
{
	printf("minishell: syntax error near unexpected token `%s\'\n", str);
	return (1);
}

int	lexer(t_token_list **head)
{
	t_token_list	*token;

	token = *head;
	// if (!token)
	// 	return (syntax_error("newline"));
	while (token)
	{
		if (token->token_type != WORD && !token->next)
			return (syntax_error("newline"));
		else if (token->token_type != WORD
			&& token->token_type == token->next->token_type)
			return (syntax_error(token->next->token));
		token = token->next;
	}
	return (SUCCESS);
}
