/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeongin <ljeongin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:42:03 by changhle          #+#    #+#             */
/*   Updated: 2022/10/11 18:38:06 by ljeongin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "libft.h"
#include "minishell.h"

static int	check_n_option(char **cmd)
{
	int		i;
	int		j;
	int		ret;
	t_bool	is_n_option;

	ret = 0;
	i = 1;
	while (cmd[i] && cmd[i][0] == '-')
	{
		j = 0;
		while (cmd[i][++j] == 'n')
			is_n_option = TRUE;
		if (cmd[i][j] != '\0')
			is_n_option = FALSE;
		if (is_n_option)
			ret++;
		else
			return (ret);
		i++;
	}
	return (ret);
}

static void	print_arg(char **cmd)
{
	int	i;
	int	flag;

	if (cmd[1][0] == '-')
		flag = check_n_option(cmd);
	else
		flag = 0;
	i = flag + 1;
	while (cmd[i])
	{
		ft_putstr_fd(cmd[i], STDOUT_FILENO);
		i++;
		if (cmd[i])
			ft_putstr_fd(" ", STDOUT_FILENO);
	}
	if (flag == 0)
		ft_putstr_fd("\n", STDOUT_FILENO);
}

int	ft_echo(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
		i++;
	if (i < 2)
		ft_putstr_fd("\n", STDOUT_FILENO);
	else
		print_arg(cmd);
	return (0);
}
