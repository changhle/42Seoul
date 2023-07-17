/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeongin <ljeongin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:37:08 by ljeongin          #+#    #+#             */
/*   Updated: 2022/10/10 20:49:21 by ljeongin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"
#include "libft.h"

#include <unistd.h>

static void	single_cmd_builtin(
	char **cmd, t_env_list **env_list, t_fd_data fd_data
	)
{
	int	bkp_stdin;
	int	bkp_stdout;

	if (fd_data.infd == -1 || fd_data.outfd == -1)
	{
		g_exit_status = 1;
		return ;
	}
	if (fd_data.infd != STDIN_FILENO)
	{
		bkp_stdin = dup(STDIN_FILENO);
		ft_dup2(fd_data.infd, STDIN_FILENO);
	}
	if (fd_data.outfd != STDOUT_FILENO)
	{
		bkp_stdout = dup(STDOUT_FILENO);
		ft_dup2(fd_data.outfd, STDOUT_FILENO);
	}
	g_exit_status = exec_builtin(cmd, env_list);
	if (fd_data.infd != STDIN_FILENO)
		ft_dup2(bkp_stdin, STDIN_FILENO);
	if (fd_data.outfd != STDOUT_FILENO)
		ft_dup2(bkp_stdout, STDOUT_FILENO);
}

void	exec_single_cmd(t_parsed_unit *parsed_unit, t_exec_info *exec_info)
{
	t_fd_data	fd_data;

	get_infd_outfd(parsed_unit, exec_info, &fd_data);
	if (parsed_unit->cmd[0] && is_builtin(parsed_unit->cmd[0]))
	{
		single_cmd_builtin(parsed_unit->cmd, exec_info->env_head, fd_data);
		return ;
	}
	exec_info->last_pid = fork();
	if (exec_info->last_pid < 0)
		ft_perror_exit("fork() error");
	if (exec_info->last_pid == 0)
		child_process(parsed_unit->cmd, fd_data, exec_info);
	exec_info->process_cnt += 1;
	ft_close(fd_data.outfd);
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
		child_process(parsed_unit->cmd, fd_data, exec_info);
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
