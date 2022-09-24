#include "minishell.h"
#include "executor.h"
#include "libft.h"

#include <sys/stat.h>

static char	**get_path(char **envp)
{
	char	*path_addr;
	char	**ret;
	size_t	i;

	path_addr = NULL;
	i = 0;
	while (envp[i] && !path_addr)
		path_addr = ft_strnstr(envp[i++], "PATH=", 5);
	if (!path_addr)
		return (NULL);
	ret = ft_split(path_addr + 5, ':');
	if (!ret)
		return (NULL);
	return (ret);
}

static t_ret_value	get_command(char **cmd, char **path)
{
	char		*cmd_with_slash;
	char		*cmd_with_path;
	struct stat	buf;
	int			i;

	if (ft_strchr(cmd[0], '/'))
	{
		if (lstat(cmd[0], &buf) == 0)
			return (SUCCESS);
		else
			return (FAILURE);
	}
	cmd_with_slash = ft_strjoin("/", cmd[0]);
	i = 0;
	while (path[i])
	{
		cmd_with_path = ft_strjoin(path[i++], cmd_with_slash);
		if (lstat(cmd_with_path, &buf) == 0)
		{
			ft_free((void **)&cmd_with_slash);
			ft_free((void **)&cmd[0]);
			cmd[0] = cmd_with_path;
			break ;
		}
		ft_free((void **)&cmd_with_path);
	}
	if (!cmd_with_path)
	{
		ft_free((void **)&cmd_with_slash);
		return (FAILURE);
	}
	return (SUCCESS);
}

static t_bool	is_builtin(char *command)
{
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

static void	free_path(char **path)
{
	int	i;

	i = 0;
	while (path[i])
		ft_free((void **)&path[i++]);
	ft_free((void **)&path);
}

int	check_cmd_valid(t_parsed_list *parsed_list, char **envp)
{
	char	**path;

	path = get_path(envp);
	if (!path)
		return (FAILURE);
	while (parsed_list)
	{
		if (is_builtin(parsed_list->parsed_unit->cmd[0]))
		{
			parsed_list = parsed_list->next;
			continue ;
		}
		if (get_command(parsed_list->parsed_unit->cmd, path) != SUCCESS)
		{
			free_path(path);
			return (FAILURE);
		}
		parsed_list = parsed_list->next;
	}
	free_path(path);
	return (SUCCESS);
}
