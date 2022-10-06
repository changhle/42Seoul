#ifndef MINISHELL_H
# define MINISHELL_H

typedef enum e_bool				t_bool;
typedef enum e_ret_value		t_ret_value;

typedef struct s_parsed_unit	t_parsed_unit;
typedef struct s_parsed_list	t_parsed_list;
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

/*
**	global var
*/
extern int						g_exit_status;

/*
**	shell
*/

void			printf_shell_banner(void);

void			loop_readline(char **envp);
char			*read_shell_line(char *prompt);

void			init_env(char **envp, t_env_list **env);
t_env_list		*add_env_node(t_env_list **env);
void			free_env_list(t_env_list *env_list);

/*
**	parser
*/
int				parse(
					char *line,
					t_parsed_list **parsed_head,
					t_env_list **env_list
					);

/*
**	executor
*/
void			execute(t_parsed_list *parsed__list, t_env_list **env_list);

/*
**	builtin
*/
int				ft_pwd(void);
int				ft_exit(char **cmd);
int				ft_cd(char **argv);
int				ft_echo(char **argv);
int				ft_env(char **cmd, t_env_list **env_list);
int				ft_export(char **cmd, t_env_list **env_list);
char			**copy_env_key(t_env_list **env_list);
void			sort_key(char **key);
char			*get_key(char *str);
char			*get_value(char *str);
int				ft_unset(char **cmd, t_env_list **env_list);
void			remove_export(char *str, t_env_list **env_list);

#endif
