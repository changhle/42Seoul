/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:41:29 by changhle          #+#    #+#             */
/*   Updated: 2023/07/17 21:12:10 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minishell.h"

typedef enum e_token_type		t_token_type;

typedef struct s_token_info		t_token_info;
typedef struct s_token_list		t_token_list;
typedef struct s_expand_info	t_expand_info;

struct							s_parsed_list;

enum e_token_type
{
	WORD = 0,
	REDIRECT,
	PIPE
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
	int		i;
	int		start;
	int		quote;
	char	*buf;
	char	*env_buf;
};

/*
**	tokenizer
*/
void			tokenizer(char *line, t_token_list **token);
void			free_token_list(t_token_list *token_list);

void			init_token(char *line, t_token_info *info);
char			set_quote(char quote, char c);
int				is_space(char c);
int				is_redirect(char *str);

/*
**	expander
*/
void			expander(t_token_list **s_token_list, t_env_list **env);
void			init_expand(t_expand_info *info);
char			*comb_str(char *s1, char *s2);

/*
**	lexer && parser
*/
int				lexer(t_token_list **head);
void			mini_parse(
					t_token_list *token_head, t_parsed_list **parsed_head
					);
void			add_redirect_node(
					t_redirect_list **head,
					t_token_list *token,
					t_redirect_type type
					);
void			free_old_cmd(char **cmd);

#endif
