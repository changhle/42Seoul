#include "minishell.h"
#include "executor.h"
#include "libft.h"

#include <unistd.h>
#include <stdio.h> ///////// temp

static void	child_process(char **cmd, int infd, int outfd, char **envp)
{
	if (infd != STDIN_FILENO)
	{
		dup2(infd, STDIN_FILENO);
		close(infd);
	}
	if (outfd != STDOUT_FILENO)
	{
		dup2(outfd, STDOUT_FILENO);
		close(outfd);
	}
	if (execve(cmd[0], cmd, envp) < 0)
		exit(1);
}

int	exec_single_cmd(t_parsed_unit *parsed_unit, t_context *context)
{
	int	infd;
	int	outfd;

	if (parsed_unit->redir_in_list)
		infd = get_infile_fd(parsed_unit->redir_in_list);
	else
		infd = STDIN_FILENO;
	if (parsed_unit->redir_out_list)
		outfd = get_outfile_fd(parsed_unit->redir_out_list);
	else
		outfd = STDOUT_FILENO;
	if (is_builtin(parsed_unit->cmd[0]))
		return (printf("exec_builtin: %s\n", parsed_unit->cmd[0])); /// return exec_builtin();
	context->last_pid = fork();
	if (context->last_pid < 0)
		exit(1); ///// error
	if (context->last_pid == 0)
	{
		child_process(parsed_unit->cmd, infd, outfd, context->envp);
		write(1, "\n", 1);
	}
	signal(SIGINT, SIG_IGN);
	return (SUCCESS);
};
