#ifndef PARSER_H
# define PARSER_H

typedef enum e_token_type	t_token_type;

typedef struct s_token_info	t_token_info;
typedef struct s_token_list	t_token_list;

enum e_token_type
{
	WORD = 0,
	REDIRECT,
	PIPE,
	DQUOTE
};

struct s_token_list
{
	char				*token;
	enum e_token_type	token_type;
	struct s_token_list	*next;
};

struct s_token_info
{
	int		space;
	int		buf_index;
	int		flag;
	char	quote;
	char	*buf;
};

/*
**	tokenizer
*/
void			tokenizer(char *line, t_token_list **token);

void			init_token(char *line, t_token_info *info);
char			set_quote(char quote, char c);
int				is_space(char c);
int				is_redirect(char *str);

/*
**	lexer && parser
*/
int				lexer(t_token_list **head);
int				mini_parse(
	t_token_list *token_head, t_parsed_list **parsed_head
	);

#endif
