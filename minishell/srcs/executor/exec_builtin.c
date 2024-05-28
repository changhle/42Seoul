/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:37:01 by changhle          #+#    #+#             */
/*   Updated: 2023/07/17 21:12:44 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"
#include "builtin.h"
#include "libft.h"

t_bool	is_builtin(char *command)
{
	if (!command)
		return (FALSE);
	return (
		ft_iseq(command, "echo")
		|| ft_iseq(command, "cd")
		|| ft_iseq(command, "pwd")
		|| ft_iseq(command, "export")
		|| ft_iseq(command, "unset")
		|| ft_iseq(command, "env")
		|| ft_iseq(command, "exit")
	);
}

int	exec_builtin(char **cmd, t_env_list **env_list)
{
	if (ft_iseq(cmd[0], "cd"))
		g_exit_status = (ft_cd(cmd, env_list));
	if (ft_iseq(cmd[0], "echo"))
		g_exit_status = (ft_echo(cmd));
	if (ft_iseq(cmd[0], "exit"))
		g_exit_status = (ft_exit(cmd));
	if (ft_iseq(cmd[0], "pwd"))
		g_exit_status = (ft_pwd());
	if (ft_iseq(cmd[0], "env"))
		g_exit_status = (ft_env(cmd, env_list));
	if (ft_iseq(cmd[0], "export"))
		g_exit_status = (ft_export(cmd, env_list));
	if (ft_iseq(cmd[0], "unset"))
		g_exit_status = (ft_unset(cmd, env_list));
	return (g_exit_status);
}
