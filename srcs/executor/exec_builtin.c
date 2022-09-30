#include "executor.h"
#include "libft.h"

int	exec_builtin(char **cmd, t_env_list **env_list)
{
	int	ret;

	ret = 0;
	if (ft_iseq(cmd[0], "cd"))
		ret = ft_cd(cmd);
	else if (ft_iseq(cmd[0], "echo"))
		ret = ft_echo(cmd);
	else if (ft_iseq(cmd[0], "exit"))
		ret = ft_exit(0);
	else if (ft_iseq(cmd[0], "pwd"))
		ret = ft_pwd();
	else if (ft_iseq(cmd[0], "env"))
		ret = ft_env(cmd, env_list);
	else if (ft_iseq(cmd[0], "export"))
		ret = ft_export(cmd, env_list);
	else if (ft_iseq(cmd[0], "unset"))
		ret = ft_unset(cmd, env_list);
	return (ret);
}