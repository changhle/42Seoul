#include <stdlib.h>
#include <stdio.h>

#include "minishell.h"
#include "parser.h"
#include "libft.h"

static void	test_print_token(t_token_list *token_list)
{
	while (token_list)
	{
		printf("token : %s\n", token_list->token);
		if (token_list->token_type == WORD)
			printf("type : WORD\n");
		else if (token_list->token_type == REDIRECT)
			printf("type : REDIRECT\n");
		else if (token_list->token_type == PIPE)
			printf("type : PIPE\n");
		token_list = token_list->next;
		printf("=================\n");
	}
}

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
			printf("included \\ or ;\n");
			return (1);
		}
		line++;
	}
	if (quote != 0)
	{
		printf("quote error\n");
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

/********** TO-DO **********/

/*
	need to handle quote more thoroughly
	ex)
	[ bash$ echo "'hello'" ] should be [ 'hello' ]
	[ bash$ echo '"hello"' ] should be [ "hello" ]
*/

/*
	could be easier to handle list if making it doubly linked list, not just singly linked list
	// 양방향 연결 리스트로 만들면 중간에 노드 삭제 등을 하는 경우 등을 다루기가 편해질 거라는 iyun의 말이 있었음...
*/

/*
	re-parse (a.k.a. mini_parse)
*/

int	parse(char *line, t_parsed_list **parsed_head)
{
	t_token_list	*token_head;
	int				ret_value;

	if (not_interpret(line))
		return (FAILURE); // need to free token_list to handle leaks before return
	token_head = NULL;
	tokenizer(line, &token_head);
	ret_value = lexer(&token_head);
	if (ret_value == FAILURE)
		return (ret_value);
	test_print_token(token_head);
	ret_value = mini_parse(token_head, parsed_head);
	free_token_list(token_head);
	return (ret_value);
}
