#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "minishell.h"
# include <stdlib.h>

typedef struct s_exec_info	t_exec_info;
typedef struct s_fd_data	t_fd_data;

enum e_exit_status
{
	ERROR_EXIT = 125,
	SIGNAL_EXIT = 128
};

struct s_exec_info
{
	t_parsed_list	*parsed_head;
	t_env_list		*env_head;
	char			**envp;
	size_t			process_cnt;
	pid_t			last_pid;
	t_bool			is_first;
	t_bool			is_last;
	int				inpipe_fd;
};

struct s_fd_data
{
	int	pipeline[2];
	int	infd;
	int	outfd;
};

void		exec_single_cmd(t_parsed_unit *parsed_unit, t_exec_info *exec_info);
void		exec_multiple_cmd(
				t_parsed_unit *parsed_unit, t_exec_info *exec_info
				);
int			exec_builtin(char **cmd, t_env_list **env_list);
t_bool		is_builtin(char *command);

void		init_exec_info(
				t_exec_info *exec_info,
				t_parsed_list **parsed_list,
				t_env_list *env_list
				);

void		free_parsed_list(t_parsed_list **parsed_list);

void		get_cmd_with_path(char **cmd, t_env_list *env_list);

int			get_infile_fd(t_redirect_list *redir_in_list);
int			get_outfile_fd(t_redirect_list *redir_out_list);
int			get_heredoc_fd(char *limiter, t_bool *heredoc_sigint);

void		print_minishell_error(char *str, char *desc, int err_num);

#endif
