#include "executor.h"
#include "libft.h"

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

static t_bool	get_infd_outfd(
	t_parsed_unit	*parsed_unit, t_exec_info *exec_info, t_fd_data *fd_data
	)
{
	if (parsed_unit->redir_in_list)
		fd_data->infd = get_infile_fd(parsed_unit->redir_in_list);
	else if (exec_info->is_first)
		fd_data->infd = STDIN_FILENO;
	else
		fd_data->infd = exec_info->inpipe_fd;
	if (parsed_unit->redir_out_list)
		fd_data->outfd = get_outfile_fd(parsed_unit->redir_out_list);
	else if (exec_info->is_last)
		fd_data->outfd = STDOUT_FILENO;
	else
		fd_data->outfd = fd_data->pipeline[1];
	return ((fd_data->infd == -1 || fd_data->outfd == -1));
}

static void	child_process(
	char **cmd, t_fd_data *fd_data, t_exec_info *exec_info
	)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	get_cmd_with_path(cmd, exec_info->env_head);
	if (!exec_info->is_last)
		ft_close(fd_data->pipeline[0]);
	if (fd_data->infd != STDIN_FILENO)
		ft_dup2(fd_data->infd, STDIN_FILENO);
	if (fd_data->outfd != STDOUT_FILENO)
		ft_dup2(fd_data->outfd, STDOUT_FILENO);
	if (is_builtin(cmd[0]))
		exit(exec_builtin(cmd, &exec_info->env_head));
	if (fd_data->infd == -1 || fd_data->outfd == -1)
		exit(FAILURE);
	else if (!cmd[0])
		exit(SUCCESS);
	if (execve(cmd[0], cmd, exec_info->envp) < 0)
		print_minishell_error(cmd[0], "command not found", 127);
	exit(127);
}

void	exec_multiple_cmd(t_parsed_unit *parsed_unit, t_exec_info *exec_info)
{
	t_fd_data	fd_data;

	if (!exec_info->is_last)
		ft_pipe(fd_data.pipeline);
	get_infd_outfd(parsed_unit, exec_info, &fd_data);
	exec_info->last_pid = fork();
	if (exec_info->last_pid < 0)
		ft_perror_exit("fork() error");
	if (exec_info->last_pid == 0)
		child_process(parsed_unit->cmd, &fd_data, exec_info);
	exec_info->process_cnt += 1;
	if (!exec_info->is_first)
		ft_close(exec_info->inpipe_fd);
	if (!exec_info->is_last)
		ft_close(fd_data.pipeline[1]);
	if (parsed_unit->redir_in_list)
		ft_close(fd_data.infd);
	if (parsed_unit->redir_out_list)
		ft_close(fd_data.outfd);
	if (!exec_info->is_last)
		exec_info->inpipe_fd = fd_data.pipeline[0];
}
