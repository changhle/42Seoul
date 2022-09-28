#include "minishell.h"
#include "executor.h"
#include "libft.h"

#include <unistd.h>

// static int	get_builtin(char **cmd)
// {
// 	if (ft_iseq(cmd[0], "echo"))
// 		return (FAILURE); // return (ft_echo());
// 	if (ft_iseq(cmd[0], "cd"))
// 		return (FAILURE); // return (ft_cd());
// 	if (ft_iseq(cmd[0], "pwd"))
// 		return (FAILURE); // return (ft_pwd());
// 	if (ft_iseq(cmd[0], "export"))
// 		return (FAILURE); // return (ft_export());
// 	if (ft_iseq(cmd[0], "unset"))
// 		return (FAILURE); // return (ft_unset());
// 	if (ft_iseq(cmd[0], "env"))
// 		return (FAILURE); // return (ft_env());
// 	if (ft_iseq(cmd[0], "exit"))
// 		return (FAILURE); // return (ft_exit());
// 	return (SUCCESS);
// }

// static int	exec_builtin(char **cmd, t_context *context) ///////////////
// {
// 	(void)cmd; (void)context;
// 	return (SUCCESS);
// }

int	exec_command_unit(t_parsed_unit *parsed_unit, t_context *context)
{
	if (context->pipe_info.is_first && context->pipe_info.is_last)
		return(exec_single_cmd(parsed_unit, context));
	if (context->pipe_info.is_first)
		return(exec_first_cmd(parsed_unit, context));
	if (context->pipe_info.is_last)
		return(exec_last_cmd(parsed_unit, context));
	return(exec_mid_cmd(parsed_unit, context));
}

// static int	get_infd(t_parsed_unit *parsed_unit, t_pipe_info *pipe_info)
// {
// 	int	infd;

// 	if (!parsed_unit->redir_in_list)
// 	{
// 		if (pipe_info.is_first)
// 			infd = STDIN_FILENO;
// 		else
// 			infd = pipe_info.inpipe_fd;
// 	}
// 	else
// 	{
// 		if (!pipe_info.is_first)
// 			close(pipe_info.inpipe_fd);
// 		infd = get_infile_fd(parsed_unit->redir_in_list);
// 	}
// 	return (infd);
// }

// static int	get_outfd(t_parsed_unit *parsed_unit) //, t_pipe_info *pipe_info)
// {
// 	int	outfd;

// 	// if (!parsed_unit->redir_in_list)
// 	// {
// 	// 	if (pipe_info.is_last)
// 	// 		outfd = STDOUT_FILENO;
// 	// }
// 	if (!parsed_unit->redir_out_list)
// 		outfd = STDOUT_FILENO;
// 	else
// 		outfd = get_outfile_fd(parsed_unit->redir_out_list);
// 	return (outfd);
// }

// static t_ret_value	get_infd_outfd(
// 	int *infd, int *outfd, t_parsed_unit *parsed_unit, t_pipe_info *pipe_info
// 	)
// {
// 	*infd = get_infd(parsed_unit, pipe_info);
// 	if (*infd == -1)
// 		return (FAILURE);
// 	*outfd = get_outfd(parsed_unit); //, pipe_info);
// 	if (*outfd == -1)
// 		return (FAILURE);
// 	return (SUCCESS);
// }

// static void	child_process(char **cmd, int pipeline[2], char **envp, int infd)
// {
// 	close(pipeline[0]);
// 	if (infd != STDIN_FILENO)
// 	{
// 		dup2(infd, STDIN_FILENO);
// 		close(infd);
// 	}
// 	dup2(pipeline[1], STDOUT_FILENO);
// 	close(pipeline[1]);
// 	if (execve(cmd[0], cmd, envp) < 0)
// 		exit(1);
// }

// int	exec_command_unit(t_parsed_unit *parsed_unit, t_context *context)
// {
// 	int	pipeline[2];
// 	int	infd;
// 	// int	outfd;

// 	if (!context->pipe_info.is_last)
// 		pipe(pipeline);
// 	// if (get_infd_outfd(&infd, &outfd, parsed_unit, context->pipe_info) != SUCCESS)
// 	// 	return (FAILURE);
// 	infd = get_infd(parsed_unit, context->pipe_info);
// 	if (is_builtin(parsed_unit->cmd[0]))
// 		exec_builtin(parsed_unit->cmd, context);
// 	else
// 	{
// 		context->last_pid = fork();
// 		if (context->last_pid < 0)
// 			; // error_exit
// 		if (context->last_pid == 0)
// 			child_process(parsed_unit->cmd, pipeline, context->envp, infd);
// 	}
// 	if (infd != STDIN_FILENO)
// 	close(infd);
// 	close(pipeline[1]);
// 	context->pipe_info.inpipe_fd = pipeline[0];
// 	return (FALSE); /////////// temp
// }
