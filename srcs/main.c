/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeongin <ljeongin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:37:30 by ljeongin          #+#    #+#             */
/*   Updated: 2022/10/11 18:44:13 by ljeongin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "minishell.h"
#include "libft.h"

extern char	**environ;

static int	argc_error(char **argv)
{
	if (argv[1])
		ft_putstr_fd("Error: Invalid number of argument\n", STDERR_FILENO);
	return (FAILURE);
}

int	main(int argc, char **argv)
{
	if (argc != 1)
		return (argc_error(argv));
	printf_shell_banner();
	loop_readline(environ);
	return (SUCCESS);
}
