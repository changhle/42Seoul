/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:37:30 by changhle          #+#    #+#             */
/*   Updated: 2023/07/17 21:12:44 by changhle         ###   ########.fr       */
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
