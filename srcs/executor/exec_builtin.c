#include "executor.h"
#include "libft.h"

int	exec_builtin(char **cmd, t_env_list **env_list)
{
	if (ft_iseq(cmd[0], "cd"))
		g_status = (ft_cd(cmd));
	if (ft_iseq(cmd[0], "echo"))
		g_status = (ft_echo(cmd));
	if (ft_iseq(cmd[0], "exit"))
		g_status = (ft_exit(cmd));
	if (ft_iseq(cmd[0], "pwd"))
		g_status = (ft_pwd());
	if (ft_iseq(cmd[0], "env"))
		g_status = (ft_env(cmd, env_list));
	if (ft_iseq(cmd[0], "export"))
		g_status = (ft_export(cmd, env_list));
	if (ft_iseq(cmd[0], "unset"))
		g_status = (ft_unset(cmd, env_list));
	return (FAILURE);
}
