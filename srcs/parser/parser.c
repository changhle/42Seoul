#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#include "minishell.h"
#include "parser.h"
#include "libft.h"

// static void	test_print_token(t_token_list *token_list)
// {
// 	printf("\n=================TOKEN=================\n\n");
// 	while (token_list)
// 	{
// 		printf("token : %s\n", token_list->token);
// 		if (token_list->token_type == WORD)
// 			printf("type : WORD\n");
// 		else if (token_list->token_type == REDIRECT)
// 			printf("type : REDIRECT\n");
// 		else if (token_list->token_type == PIPE)
// 			printf("type : PIPE\n");
// 		token_list = token_list->next;
// 		if (token_list)
// 			printf("------------------\n");
// 	}
// }

// static void	test_print_unit(t_parsed_list *parsed_head)
// {
// 	int	i;
// 	t_redirect_list	*tmp;

// 	printf("\n=================UNIT=================\n\n");
// 	while (parsed_head)
// 	{
// 		if (parsed_head->parsed_unit->cmd)
// 		{
// 			i = 0;
// 			printf("-------------CMD-------------\n");
// 			while (parsed_head->parsed_unit->cmd[i])
// 			{
// 				printf("cmd[%d] : %s\n", i, parsed_head->parsed_unit->cmd[i]);
// 				i++;
// 			}
// 			printf("-----------------------------\n");
// 		}
// 		tmp = parsed_head->parsed_unit->redir_in_list;
// 		if (tmp)
// 			printf("\n----------REDIR__IN----------\n");
// 		while (tmp)
// 		{
// 			if (tmp->redir_type == 1)
// 				printf("REDIR_TYPE : REDIR_IN\n");
// 			else if (tmp->redir_type == 2)
// 				printf("REDIR_TYPE : REDIR_IN_APPEND\n");
// 			printf("FILENAME : %s\n", tmp->filename);
// 			tmp = tmp->next;
// 			printf("-----------------------------\n");
// 		}
// 		tmp = parsed_head->parsed_unit->redir_out_list;
// 		if (tmp)
// 			printf("\n----------REDIR_OUT----------\n");
// 		while (tmp)
// 		{
// 			if (tmp->redir_type == 3)
// 				printf("REDIR_TYPE : REDIR_OUT\n");
// 			else if (tmp->redir_type == 4)
// 				printf("REDIR_TYPE : REDIR_OUT_APPEND\n");
// 			printf("FILENAME : %s\n", tmp->filename);
// 			tmp = tmp->next;
// 			printf("-----------------------------\n");
// 		}
// 		parsed_head = parsed_head->next;
// 		if (parsed_head)
// 			printf("\n=================PIPE=================\n\n");
// 	}
// }

int	not_interpret(char *line)
{
	char	quote;

	quote = 0;
	while (*line)
	{
		if (*line == '\'' || *line == '\"')
			quote = set_quote(quote, *line);
		else if (quote == 0 && (*line == '\\' || *line == ';'))
		{
			ft_putstr_fd("minishell: syntax error near unexpected char `", STDERR_FILENO);
			ft_putchar_fd((*line), STDERR_FILENO);
			ft_putstr_fd("\'\n", STDERR_FILENO);
			return (1);
		}
		line++;
	}
	if (quote != 0)
	{
		ft_putstr_fd("minishell: syntax error near unclosed quote `", STDERR_FILENO);
		ft_putchar_fd(quote, STDERR_FILENO);
		ft_putstr_fd("\'\n", STDERR_FILENO);
		return (1);
	}
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
	t_token_list	*tmp;
	int				ret_value;

	if (not_interpret(line))
	{
		g_exit_status = 1;
		return (FAILURE); // need to free token_list to handle leaks before return
	}
	// line = expander(line, env_list);
	token_head = NULL;
	tokenizer(line, &token_head);
	ret_value = lexer(&token_head);
	if (ret_value == FAILURE)
	{
		g_exit_status = 258;
		// free(line);
		free_token_list(token_head);
		return (ret_value);
	}
	expander(&token_head, env_list);
	tmp = token_head;
	token_head = word_split(&token_head);
	// test_print_token(token_head);
	free_token_list(tmp);
	remove_quote(&token_head);
	*parsed_head = NULL;
	mini_parse(token_head, parsed_head);
	// test_print_unit(*parsed_head);
	free_token_list(token_head);
	// free(line);
	return (ret_value);
}
