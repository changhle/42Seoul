#include "executor.h"
#include "libft.h"

#include <fcntl.h>
#include <unistd.h>

static void	add_nl_to_limiter(t_redirect_list *redir_in_list)
{
	char	*tmp;

	tmp = ft_strjoin(redir_in_list->filename, "\n");
	ft_free((void **)&redir_in_list->filename);
	redir_in_list->filename = tmp;
}

static int	open_infile(t_redirect_list *redir_in_list, t_bool *is_no_heredoc)
{
	if (redir_in_list->redir_type == REDIR_IN_APPEND)
		return (get_heredoc_fd(redir_in_list->filename, is_no_heredoc));
	*is_no_heredoc = FALSE;
	return (open(redir_in_list->filename, O_RDONLY));
}

int	get_infile_fd(t_redirect_list *redir_in_list)
{
	int		fd;
	char	*err_filename;
	t_bool	is_no_heredoc;

	err_filename = NULL;
	while (redir_in_list)
	{
		if (redir_in_list->redir_type == REDIR_IN_APPEND)
			add_nl_to_limiter(redir_in_list);
		fd = open_infile(redir_in_list, &is_no_heredoc);
		if (fd == -1 && !err_filename
			&& !(redir_in_list->redir_type == REDIR_IN_APPEND))
			err_filename = redir_in_list->filename;
		if (fd != -1 && redir_in_list->next)
			ft_close(fd);
		redir_in_list = redir_in_list->next;
	}
	if (err_filename || is_no_heredoc)
	{
		if (err_filename)
			print_minishell_error(err_filename, NULL, 0);
		return (-1);
	}
	return (fd);
}
