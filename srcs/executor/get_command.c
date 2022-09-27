#include "minishell.h"
#include "executor.h"
#include "libft.h"

#include <sys/stat.h>

t_bool	is_builtin(char *command)
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

static t_ret_value	is_existing_file(char *file)
{
	struct stat	buf;

	if (lstat(file, &buf) == 0)
		return (SUCCESS);
	return (FAILURE);
}

t_ret_value	get_command(char **cmd, char **path)
{
	char		*cmd_with_slash;
	char		*cmd_with_path;
	size_t		i;

	if (ft_strchr(cmd[0], '/'))
		return(is_existing_file(cmd[0]));
	cmd_with_slash = ft_strjoin("/", cmd[0]);
	i = 0;
	while (path[i])
	{
		cmd_with_path = ft_strjoin(path[i++], cmd_with_slash);
		if (is_existing_file(cmd_with_path) == SUCCESS)
		{
			ft_free((void **)&cmd[0]);
			cmd[0] = cmd_with_path;
			break ;
		}
		ft_free((void **)&cmd_with_path);
	}
	ft_free((void **)&cmd_with_slash);
	if (!cmd_with_path)
		return (FAILURE);
	return (SUCCESS);
}
