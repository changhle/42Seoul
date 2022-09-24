// #include "minishell.h"
// #include "executor.h"
// #include "libft.h"

// #include <sys/stat.h>

// static t_ret_value	get_command(char **cmd, char **path)
// {
// 	char		*cmd_with_slash;
// 	char		*cmd_with_path;
// 	struct stat	buf;
// 	int			i;

// 	if (ft_strchr(cmd[0], '/'))
// 	{
// 		if (lstat(cmd[0], &buf) == 0)
// 			return (SUCCESS);
// 		else
// 			return (FAILURE);
// 	}
// 	cmd_with_slash = ft_strjoin("/", cmd[0]);
// 	i = 0;
// 	while (path[i])
// 	{
// 		cmd_with_path = ft_strjoin(path[i++], cmd_with_slash);
// 		if (lstat(cmd_with_path, &buf) == 0)
// 		{
// 			ft_free((void **)&cmd_with_slash);
// 			ft_free((void **)&cmd[0]);
// 			cmd[0] = cmd_with_path;
// 			break ;
// 		}
// 		ft_free((void **)&cmd_with_path);
// 	}
// 	if (!cmd_with_path)
// 	{
// 		ft_free((void **)&cmd_with_slash);
// 		return (FAILURE);
// 	}
// 	return (SUCCESS);
// }


// int	check_infile_valid(t_parsed_list *parsed_list, char **envp)
// {
// 	if (!parsed_list)
// 	while (parsed_list)
// 	{
// 		if (get_command(parsed_list->parsed_unit->) != SUCCESS)
// 			return (FAILURE);
// 		parsed_list = parsed_list->next;
// 	}
// 	return (SUCCESS);
// }
