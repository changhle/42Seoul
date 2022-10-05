#include "executor.h"
#include "libft.h"

#include <fcntl.h>
#include <unistd.h>

static void	open_close_outfile(char *filename, int is_append)
{
	int	fd;

	if (is_append)
		fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0666);
	else
		fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd == -1)
		ft_perror_exit("open() error");
	ft_close(fd);
}

static int	open_last_outfile(char *filename, int is_append)
{
	int	fd;

	if (is_append)
		fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0666);
	else
		fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd == -1)
		ft_perror_exit("open() error");
	return (fd);
}

int	get_outfile_fd(t_redirect_list *redir_out_list)
{
	while (redir_out_list && redir_out_list->next)
	{
		open_close_outfile(
			redir_out_list->filename,
			redir_out_list->redir_type == REDIR_OUT_APPEND
			);
		redir_out_list = redir_out_list->next;
	}
	return (open_last_outfile(
			redir_out_list->filename,
			redir_out_list->redir_type == REDIR_OUT_APPEND
		));
}
