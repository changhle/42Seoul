#include "minishell.h"
#include "executor.h"
#include "libft.h"

#include <stdio.h>

static char	**get_path(t_env_list *env_list)
{
	char	**ret;

	while (env_list && ft_strncmp(env_list->key, "PATH", 4))
		env_list = env_list->next;
	if (!env_list)
		return (NULL);
	ret = ft_split(env_list->value, ':');
	if (!ret)
		return (NULL);
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

static int	command_not_found(
	char *cmd, t_redirect_list *redir_in_list, char **path
	)
{
	get_infile_fd(redir_in_list);
	printf("minishell: %s: command not found\n", cmd);
	free_path(path);
	return (127);
}

static void	add_nl_if_redir_append(t_redirect_list *redir_in_list)
{
	char	*tmp;

	while (redir_in_list)
	{
		if (redir_in_list->redir_type == REDIR_IN_APPEND)
		{
			tmp = ft_strjoin(redir_in_list->filename, "\n");
			ft_free((void **)&redir_in_list->filename);
			redir_in_list->filename = tmp;
		}
		redir_in_list = redir_in_list->next;
	}
}

int	check_cmd_valid(t_parsed_list *parsed_list, t_env_list *env_list)
{
	char	**path;

	if (!parsed_list->parsed_unit || !parsed_list->parsed_unit->cmd)
		return (FAILURE);
	path = get_path(env_list);
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
			return (command_not_found(
				parsed_list->parsed_unit->cmd[0],
				parsed_list->parsed_unit->redir_in_list,
				path));
		add_nl_if_redir_append(parsed_list->parsed_unit->redir_in_list);
		parsed_list = parsed_list->next;
	}
	free_path(path);
	return (SUCCESS);
}
