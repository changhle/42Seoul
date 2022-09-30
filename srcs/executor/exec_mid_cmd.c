#include "minishell.h"
#include "executor.h"
#include "libft.h"

#include <unistd.h>
#include <stdio.h> ///////// temp

static void	child_process(char **cmd, t_temp_info *temp_info, t_context *context)
{
	close(temp_info->pipeline[0]);
	dup2(temp_info->infd, STDIN_FILENO);
	close(temp_info->infd);
	dup2(temp_info->outfd, STDOUT_FILENO);
	close(temp_info->outfd);
	if (is_builtin(cmd[0]))
	{
		exec_builtin(cmd, &context->env_head);
		// printf("exec_builtin: %s\n", cmd[0]); /// return exec_builtin();
		exit(SUCCESS);
	}
	if (execve(cmd[0], cmd, context->envp) < 0)
		exit(FAILURE); /// error
}

int	exec_mid_cmd(t_parsed_unit *parsed_unit, t_context *context)
{
	t_temp_info	temp_info;

	if (pipe(temp_info.pipeline) < 0)
		exit(FAILURE); //////// temp
	if (parsed_unit->redir_in_list)
		temp_info.infd = get_infile_fd(parsed_unit->redir_in_list);
	else
		temp_info.infd = context->pipe_info.inpipe_fd;
	if (parsed_unit->redir_out_list)
		temp_info.outfd = get_outfile_fd(parsed_unit->redir_out_list);
	else
		temp_info.outfd = temp_info.pipeline[1];
	context->last_pid = fork();
	if (context->last_pid < 0)
		exit(FAILURE); ///// error
	if (context->last_pid == 0)
		child_process(parsed_unit->cmd, &temp_info, context);
	close(temp_info.pipeline[1]);
	close(temp_info.infd);
	context->pipe_info.inpipe_fd = temp_info.pipeline[0];
	return (SUCCESS);
};
