#include "executor.h"
#include "libft.h"

#include <unistd.h>
#include <stdlib.h>

static t_bool	get_infd_outfd(
	t_parsed_unit *parsed_unit, int *infd, int *outfd
	)
{
	if (parsed_unit->redir_in_list)
	{
		*infd = get_infile_fd(parsed_unit->redir_in_list);
		if (*infd == -1)
			return (FALSE);
	}
	else
		*infd = STDIN_FILENO;
	if (parsed_unit->redir_out_list)
		*outfd = get_outfile_fd(parsed_unit->redir_out_list);
	else
		*outfd = STDOUT_FILENO;
	return (TRUE);
}

static void	single_cmd_builtin(
	char **cmd, t_env_list **env_list, int infd, int outfd
	)
{
	int	bkp_stdin;
	int	bkp_stdout;

	if (infd != STDIN_FILENO)
	{
		bkp_stdin = dup(STDIN_FILENO);
		ft_dup2(infd, STDIN_FILENO);
	}
	if (outfd != STDOUT_FILENO)
	{
		bkp_stdout = dup(STDOUT_FILENO);
		ft_dup2(outfd, STDOUT_FILENO);
	}
	set_exit_status(exec_builtin(cmd, env_list));
	if (infd != STDIN_FILENO)
		ft_dup2(bkp_stdin, STDIN_FILENO);
	if (outfd != STDOUT_FILENO)
		ft_dup2(bkp_stdout, STDOUT_FILENO);
}

static void	child_process(
	char **cmd, int infd, int outfd, t_exec_info *exec_info
	)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	get_cmd_with_path(cmd, exec_info->env_head);
	if (infd != STDIN_FILENO)
		ft_dup2(infd, STDIN_FILENO);
	if (outfd != STDOUT_FILENO)
		ft_dup2(outfd, STDOUT_FILENO);
	if (execve(cmd[0], cmd, exec_info->envp) < 0)
		print_minishell_error(cmd[0], "command not found", 127);
	exit(FAILURE);
}

void	exec_single_cmd(t_parsed_unit *parsed_unit, t_exec_info *exec_info)
{
	int		infd;
	int		outfd;
	t_bool	has_valid_infile;

	has_valid_infile = get_infd_outfd(parsed_unit, &infd, &outfd);
	if (is_builtin(parsed_unit->cmd[0]) && has_valid_infile)
	{
		single_cmd_builtin(parsed_unit->cmd, &exec_info->env_head, infd, outfd);
		return ;
	}
	if (has_valid_infile)
	{
		exec_info->last_pid = fork();
		if (exec_info->last_pid < 0)
			ft_perror_exit("fork() error");
		if (exec_info->last_pid == 0)
			child_process(parsed_unit->cmd, infd, outfd, exec_info);
		exec_info->process_cnt += 1;
	}
	ft_close(outfd);
}
