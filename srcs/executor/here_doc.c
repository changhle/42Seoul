#include "executor.h"
#include "libft.h"
#include "get_next_line.h"

#include <stdio.h>
#include <signal.h>

static int	wait_child(pid_t pid)
{
	int		status;
	int		wait_val;
	int		ret;

	wait_val = wait(&status);
	if (wait_val == -1)
		return (FAILURE);
	if (wait_val == pid)
		ret = status;
	if (WIFEXITED(ret))
		return (WEXITSTATUS(ret));
	if (WIFSIGNALED(ret))
	{
		ft_putstr_fd("\n", STDERR_FILENO);
		return (WTERMSIG(ret) + SIGNAL_EXIT);
	}
	return (FAILURE);
}

static int	heredoc_child(char *limiter, int pipeline[2])
{
	char	*input;

	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_IGN);
	ft_close(pipeline[0]);
	while (1)
	{
		ft_putstr_fd("> ", STDOUT_FILENO);
		input = get_next_line(STDIN_FILENO);
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

int	get_heredoc_fd(char *limiter, t_bool *is_no_heredoc)
{
	int		pipeline[2];
	pid_t	pid;
	int		child_stat;

	if (pipe(pipeline) < 0)
		ft_perror_exit("pipe() error");
	pid = fork();
	if (pid < 0)
		ft_perror_exit("fork() error");
	if (pid == 0)
		heredoc_child(limiter, pipeline);
	ft_close(pipeline[1]);
	child_stat = wait_child(pid);
	if (child_stat != SUCCESS && child_stat != 1)
	{
		ft_close(pipeline[0]);
		*is_no_heredoc = TRUE;
		return (-1);
	}
	*is_no_heredoc = FALSE;
	return (pipeline[0]);
}
