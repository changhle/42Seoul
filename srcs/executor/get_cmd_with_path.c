/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_with_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:37:14 by changhle          #+#    #+#             */
/*   Updated: 2023/07/17 21:12:44 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"
#include "libft.h"

#include <stdio.h>
#include <sys/stat.h>

static char	**get_path(t_env_list **env_list)
{
	char	**ret;

	while ((*env_list) && ft_strncmp((*env_list)->key, "PATH", 4))
		(*env_list) = (*env_list)->next;
	if (!(*env_list))
	{
		ret = ft_malloc(sizeof(char *));
		ret[0] = NULL;
	}
	else
		ret = ft_split((*env_list)->value, ':');
	return (ret);
}

static void	free_path(char **path)
{
	int	i;

	i = 0;
	while (path[i])
		ft_free((void **)&path[i++]);
	ft_free((void **)&path);
}

static void	get_command(char **cmd, char **path)
{
	char		*cmd_with_slash;
	char		*cmd_with_path;
	struct stat	buf;
	size_t		i;

	if (ft_strchr(cmd[0], '/') || ft_iseq(cmd[0], "\0"))
		return ;
	cmd_with_slash = ft_strjoin("/", cmd[0]);
	i = 0;
	while (path[i])
	{
		cmd_with_path = ft_strjoin(path[i++], cmd_with_slash);
		if (lstat(cmd_with_path, &buf) == 0)
		{
			ft_free((void **)&cmd[0]);
			cmd[0] = cmd_with_path;
			break ;
		}
		ft_free((void **)&cmd_with_path);
	}
	ft_free((void **)&cmd_with_slash);
}

void	get_cmd_with_path(char **cmd, t_env_list **env_list)
{
	char	**path;

	if (!cmd[0] || is_builtin(cmd[0]))
		return ;
	path = get_path(env_list);
	get_command(cmd, path);
	free_path(path);
}
