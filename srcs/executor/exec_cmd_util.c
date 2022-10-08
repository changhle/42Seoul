#include "minishell.h"
#include "executor.h"
#include "libft.h"

#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/errno.h>

void	get_infd_outfd(
	t_parsed_unit *parsed_unit, t_exec_info *exec_info, t_fd_data *fd_data
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
}

void	ft_execve(char **cmd, char **envp, t_env_list *env_list)
{
	struct stat	buf;

	if (!ft_strchr(cmd[0], '/'))
	{
		while (env_list && ft_strncmp(env_list->key, "PATH", 4))
			env_list = env_list->next;
		if (env_list)
		{
			print_minishell_error(cmd[0], "command not found", 127);
			exit(127);
		}
	}
	if (execve(cmd[0], cmd, envp) < 0)
	{
		if (lstat(cmd[0], &buf) == 0)
		{
			print_minishell_error(cmd[0], NULL, 126);
			exit(126);
		}
		else
		{
			print_minishell_error(cmd[0], NULL, 127);
			exit(127);
		}
	}
}

void	child_process(char **cmd, t_fd_data fd_data, t_exec_info *exec_info)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	get_cmd_with_path(cmd, exec_info->env_head);
	if (!exec_info->is_last)
		ft_close(fd_data.pipeline[0]);
	if (fd_data.infd != STDIN_FILENO)
		ft_dup2(fd_data.infd, STDIN_FILENO);
	if (fd_data.outfd != STDOUT_FILENO)
		ft_dup2(fd_data.outfd, STDOUT_FILENO);
	if (fd_data.infd == -1 || fd_data.outfd == -1)
		exit(FAILURE);
	if (!cmd[0])
		exit(SUCCESS);
	if (is_builtin(cmd[0]))
		exit(exec_builtin(cmd, &exec_info->env_head));
	ft_execve(cmd, exec_info->envp, exec_info->env_head);
}

void	print_minishell_error(char *str, char *desc, int err_num)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	if (str)
	{
		ft_putstr_fd(str, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
	}
	if (desc)
		ft_putstr_fd(desc, STDERR_FILENO);
	else
		ft_putstr_fd(strerror(errno), STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	if (err_num)
		g_exit_status = err_num;
	else
		g_exit_status = errno;
}
