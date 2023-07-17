/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeongin <ljeongin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:39:04 by ljeongin          #+#    #+#             */
/*   Updated: 2022/10/10 18:39:05 by ljeongin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

typedef enum e_bool				t_bool;
typedef struct s_parsed_list	t_parsed_list;
typedef struct s_parsed_unit	t_parsed_unit;
typedef enum e_redirect_type	t_redirect_type;
typedef struct s_redirect_list	t_redirect_list;
typedef struct s_env_list		t_env_list;

enum e_bool
{
	FALSE = 0,
	TRUE
};

enum e_ret_value
{
	SUCCESS = 0,
	FAILURE
};

enum e_redirect_type
{
	REDIR_IN = 1,
	REDIR_IN_APPEND,
	REDIR_OUT,
	REDIR_OUT_APPEND
};

struct s_env_list
{
	char				*env;
	char				*key;
	char				*value;
	struct s_env_list	*next;
};

struct s_redirect_list
{
	enum e_redirect_type	redir_type;
	char					*filename;
	struct s_redirect_list	*next;
};

struct s_parsed_unit
{
	char					**cmd;
	struct s_redirect_list	*redir_in_list;
	struct s_redirect_list	*redir_out_list;
};

struct s_parsed_list
{
	struct s_parsed_unit	*parsed_unit;
	struct s_parsed_list	*next;
};

extern int						g_exit_status;

void	printf_shell_banner(void);
void	loop_readline(char **envp);

#endif
