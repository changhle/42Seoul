#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "minishell.h"
# include <stdlib.h>

typedef struct s_context	t_context;
typedef struct s_pipe_info	t_pipe_info;
typedef struct s_temp_info	t_temp_info;

enum e_exit_status
{
	ERROR_EXIT = 125,
	SIGNAL_EXIT = 128,
	SIG_CONT = 0x13
};

struct s_pipe_info
{
	t_bool	is_first;
	t_bool	is_last;
	int		inpipe_fd;
};

struct s_context
{
	t_parsed_list	*parsed_head;
	t_env_list		*env_head;
	char			**envp;
	size_t			process_cnt;
	t_pipe_info		pipe_info;
	pid_t			last_pid;
};

struct s_temp_info
{
	int	pipeline[2];
	int	infd;
	int	outfd;
};

int			exec_command_unit(t_parsed_unit *parsed_unit, t_context *context);
int			exec_single_cmd(t_parsed_unit *parsed_unit, t_context *context);
int			exec_first_cmd(t_parsed_unit *parsed_unit, t_context *context);
int			exec_last_cmd(t_parsed_unit *parsed_unit, t_context *context);
int			exec_mid_cmd(t_parsed_unit *parsed_unit, t_context *context);
int			exec_builtin(char **cmd, t_env_list **env_list);

void		init_context(
			t_context *context,
			t_parsed_list **parsed_list,
			t_env_list *env_list
			);

void		free_parsed_list(t_parsed_list **parsed_list);

int			check_cmd_valid(t_parsed_list *parsed_list, t_env_list *env_list);
t_ret_value	get_command(char **cmd, char **path);
t_bool		is_builtin(char *command);

int			get_infile_fd(t_redirect_list *redir_in_list);
int			get_outfile_fd(t_redirect_list *redir_out_list);

#endif
