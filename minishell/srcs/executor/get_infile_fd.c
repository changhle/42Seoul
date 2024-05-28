/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_infile_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:37:18 by changhle          #+#    #+#             */
/*   Updated: 2023/07/17 21:12:44 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"
#include "libft.h"

#include <fcntl.h>
#include <unistd.h>

static int	open_infile(
	t_redirect_list *redir_in_list, t_bool *heredoc_sigint, int *ambi_error
	)
{
	if (!redir_in_list->filename)
	{
		*ambi_error = 1;
		return (-1);
	}
	if (*ambi_error == -1)
		*ambi_error = 0;
	if (redir_in_list->redir_type == REDIR_IN_APPEND)
		return (get_heredoc_fd(redir_in_list->filename, heredoc_sigint));
	*heredoc_sigint = FALSE;
	return (open(redir_in_list->filename, O_RDONLY));
}

static int	print_error(char *err_filename)
{
	if (err_filename)
		print_minishell_error(err_filename, "No such file or directory", 1);
	else
		print_minishell_error(NULL, "ambiguous redirect", 1);
	return (-1);
}

int	get_infile_fd(t_redirect_list *redir_in_list)
{
	int		fd;
	char	*err_filename;
	int		ambiguous_error;
	t_bool	heredoc_sigint;

	err_filename = NULL;
	ambiguous_error = -1;
	while (redir_in_list)
	{
		fd = open_infile(redir_in_list, &heredoc_sigint, &ambiguous_error);
		if (heredoc_sigint)
			return (-1);
		if (fd == -1 && !err_filename && !ambiguous_error
			&& !(redir_in_list->redir_type == REDIR_IN_APPEND))
			err_filename = redir_in_list->filename;
		if (redir_in_list->next)
			ft_close(fd);
		redir_in_list = redir_in_list->next;
	}
	if (ambiguous_error == 1 || err_filename)
		return (print_error(err_filename));
	return (fd);
}
