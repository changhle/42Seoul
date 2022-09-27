#ifndef PARSER_H
# define PARSER_H

typedef enum e_token_type		t_token_type;

typedef struct s_token_info		t_token_info;
typedef struct s_token_list		t_token_list;
typedef struct s_expand_info	t_expand_info;

struct t_parsed_list;

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
	int		buf_size;
	char	quote;
	char	*buf;
};

struct s_expand_info
{
	int		index;
	int		start;
	int		quote;
	char	*buf;
	char	*env_buf;
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
**	expander
*/
void			expander(t_token_list **token, t_env_list **env);
void			init_expand(t_expand_info *info);
char			*comb_str(char *s1, char *s2);
char			*remove_quote(char *str);

/*
**	lexer && parser
*/
int				lexer(t_token_list **head);
int				mini_parse(
	t_token_list *token_head, t_parsed_list **parsed_head
	);

#endif
