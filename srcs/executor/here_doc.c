#include "minishell.h"
#include "executor.h"
#include "libft.h"

#include <stdio.h>
#include "readline.h"
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

static int	wait_child(pid_t pid)
{
	int		status;
	int		wait_val;

	wait_val = waitpid(pid, &status, 0);
	if (wait_val == -1)
		return (FAILURE);
	if (WIFSIGNALED(status))
	{
		ft_putstr_fd("\n", STDERR_FILENO);
		return (WTERMSIG(status) + SIGNAL_EXIT);
	}
	return (WEXITSTATUS(status));
}

static int	heredoc_child(char *limiter, int pipeline[2])
{
	char	*input;

	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_IGN);
	ft_close(pipeline[0]);
	while (1)
	{
		input = readline("> ");
		if (!input || ft_iseq(input, limiter))
		{
			if (input)
				ft_free((void **)&input);
			break ;
		}
		ft_putstr_fd(input, pipeline[1]);
		ft_free((void **)&input);
	}
	ft_close(pipeline[1]);
	exit(SUCCESS);
}

int	get_heredoc_fd(char *limiter, t_bool *heredoc_sigint)
{
	int		pipeline[2];
	pid_t	pid;
	int		child_stat;

	ft_pipe(pipeline);
	pid = fork();
	if (pid < 0)
		ft_perror_exit("fork() error");
	if (pid == 0)
		heredoc_child(limiter, pipeline);
	ft_close(pipeline[1]);
	child_stat = wait_child(pid);
	if (child_stat != SUCCESS)
	{
		ft_close(pipeline[0]);
		*heredoc_sigint = TRUE;
		return (-1);
	}
	*heredoc_sigint = FALSE;
	return (pipeline[0]);
}
