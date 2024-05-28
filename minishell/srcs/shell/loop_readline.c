/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_readline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:38:49 by changhle          #+#    #+#             */
/*   Updated: 2023/07/17 21:12:44 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <readline/history.h>

#include "minishell.h"
#include "shell.h"
#include "libft.h"

int	g_exit_status;

static int	write_exit_without_newline(void)
{
	write(STDERR_FILENO, "\x1b[1A", 4);
	write(STDERR_FILENO, "\033[11C", 5);
	write(STDERR_FILENO, "exit\n", 5);
	exit(g_exit_status);
}

static t_bool	is_valid_line(char	**line)
{
	char	*tmp;

	tmp = *line;
	*line = ft_strtrim(*line, " \t\r\v\f\n");
	ft_free((void **)&tmp);
	if (ft_strlen(*line))
		return (TRUE);
	return (FALSE);
}

void	loop_readline(char **envp)
{
	char			*line;
	t_env_list		*env_list;
	t_parsed_list	*parsed_list;

	init_env(envp, &env_list);
	while (42)
	{
		line = read_shell_line("\001\033[0;34m\002minishell$\001\033[0m\002 ");
		if (!line)
			write_exit_without_newline();
		if (line[0] != '\0')
			add_history(line);
		if (is_valid_line(&line))
		{
			if (parse(line, &parsed_list, &env_list) == SUCCESS)
				execute(parsed_list, &env_list);
			free_parsed_list(&parsed_list);
		}
		ft_free((void **)&line);
	}
	free_env_list(env_list);
}
