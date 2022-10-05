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

static int	ft_isnum(char *str)
{
	int	i;

	if (!ft_isdigit(str[1]) && str[1] != '+' && str[1] != '-')
		return (0);
	i = 1;
	while (str[i])
	{
		ft_putstr_fd("======\n", STDOUT_FILENO);
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_exit(char **cmd)
{
	ft_putstr_fd(cmd[0], STDOUT_FILENO);
	if (cmd[1])
	{
		if (!ft_isnum(cmd[1]))
		{
			ft_putstr_fd("exit\nminishell: exit: siodfj: numeric argument required\n", STDERR_FILENO);
			exit(255);
		}
		else if (cmd[2])
		{
			ft_putstr_fd("exit\nminishell: exit: too many arguments\n", STDERR_FILENO);
			return (1);
		}
		else
			exit(ft_atoi(cmd[1]));
	}
	ft_putstr_fd("exit\n", STDERR_FILENO);
	exit(0);
	return (0);
}
