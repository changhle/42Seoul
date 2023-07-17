/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_outfile_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeongin <ljeongin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:37:20 by ljeongin          #+#    #+#             */
/*   Updated: 2022/10/10 18:37:22 by ljeongin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"
#include "libft.h"

#include <fcntl.h>
#include <unistd.h>

static int	open_outfile(char *filename, int is_append)
{
	int	fd;

	if (!filename)
	{
		print_minishell_error(NULL, "ambiguous redirect", 1);
		return (-1);
	}
	if (is_append)
		fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0666);
	else
		fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd == -1)
		print_minishell_error(filename, NULL, 0);
	return (fd);
}

int	get_outfile_fd(t_redirect_list *redir_out_list)
{
	int	fd;

	while (redir_out_list && redir_out_list->next)
	{
		fd = open_outfile(
				redir_out_list->filename,
				redir_out_list->redir_type == REDIR_OUT_APPEND
				);
		if (fd == -1)
			return (-1);
		ft_close(fd);
		redir_out_list = redir_out_list->next;
	}
	return (open_outfile(
			redir_out_list->filename,
			redir_out_list->redir_type == REDIR_OUT_APPEND
		));
}
