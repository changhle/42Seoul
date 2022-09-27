#include "minishell.h"
#include "executor.h"
#include "libft.h"
#include "get_next_line.h"

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>

static int	exec_heredoc(char *limiter)
{
	char	*input;

	ft_putstr_fd("> ", STDOUT_FILENO);
	input = get_next_line(STDIN_FILENO);
	if (!input)
		return (-1);
	while (input && !ft_iseq(input, limiter))
	{
		free(input);
		ft_putstr_fd("> ", STDOUT_FILENO);
		input = get_next_line(STDIN_FILENO);
	}
	if (!input)
		return (-1);
	free(input);
	return (SUCCESS);
}

static int	get_heredoc_fd(char *limiter)
{
	char	*input;
	int		pipeline[2];

	if (pipe(pipeline) < 0)
		return (-1);
	ft_putstr_fd("> ", STDOUT_FILENO);
	input = get_next_line(STDIN_FILENO);
	if (!input)
		return (-1);
	while (input && !ft_iseq(input, limiter))
	{
		ft_putstr_fd(input, pipeline[1]);
		free(input);
		ft_putstr_fd("> ", STDOUT_FILENO);
		input = get_next_line(STDIN_FILENO);
	}
	if (!input)
		return (-1);
	free(input);
	close(pipeline[1]);
	return (pipeline[0]);
}

static t_bool	is_valid_infile(char *filename)
{
	struct stat	buf;

	if (lstat(filename, &buf) == 0)
		return (TRUE);
	return (FALSE);
}

static t_bool	are_all_valid_infile(t_redirect_list *redir_in_list)
{
	t_bool	ret_value;
	t_bool	error_printed;

	ret_value = TRUE;
	error_printed = FALSE;
	while (redir_in_list)
	{
		if (redir_in_list->redir_type == REDIR_IN_APPEND)
			exec_heredoc(redir_in_list->filename);
		else
		{
			if (!is_valid_infile(redir_in_list->filename))
			{
				ret_value = FALSE;
				if (error_printed == FALSE)
				{
					printf("minishell: %s: No such file or directory\n",
							redir_in_list->filename);
					error_printed = TRUE;
				}
			}
		}
		redir_in_list = redir_in_list->next;
	}
	return (ret_value);
}

int	get_infile_fd(t_redirect_list *redir_in_list)
{
	if (!redir_in_list)
		return (STDIN_FILENO);
	if (!are_all_valid_infile(redir_in_list))
		return (-1);
	while (redir_in_list && redir_in_list->next)
		redir_in_list = redir_in_list->next;
	if (redir_in_list->redir_type == REDIR_IN_APPEND)
		return (get_heredoc_fd(redir_in_list->filename));
	if (!is_valid_infile(redir_in_list->filename))
		return (-1);
	return (open(redir_in_list->filename, O_RDONLY));
}
