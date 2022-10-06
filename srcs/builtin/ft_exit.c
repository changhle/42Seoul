/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 09:57:00 by ljeongin          #+#    #+#             */
/*   Updated: 2022/10/05 17:58:48 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include "libft.h"
#include "minishell.h"

static t_bool	is_numeric(char *str)
{
	int	i;

	if (!ft_isdigit(str[0]) && str[0] != '+' && str[0] != '-')
		return (FALSE);
	i = 1;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	ft_exit(char **cmd)
{
	ft_putstr_fd("exit\n", STDOUT_FILENO);
	if (cmd[1])
	{
		if (!is_numeric(cmd[1]))
		{
			ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
			ft_putstr_fd(cmd[1], STDERR_FILENO);
			ft_putstr_fd(": numeric argument required\n", STDERR_FILENO);
			exit(255);
		}
		else if (cmd[2])
		{
			ft_putstr_fd(
				"minishell: exit: too many arguments\n", STDERR_FILENO
				);
			return (FAILURE);
		}
		else
			exit(ft_atoi(cmd[1]));
	}
	exit(SUCCESS);
	return (FAILURE);
}
