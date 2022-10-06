#include <unistd.h>
#include <string.h>
#include <errno.h>

#include "libft.h"
#include "minishell.h"

int	ft_cd(char **cmd, t_env_list **env_list)
{
	if (cmd[1])
	{
		add_export(ft_strdup("OLDPWD"), getcwd(NULL, 0), env_list);
		if (chdir(cmd[1]) == -1)
		{
			ft_putstr_fd("minishell: cd: ", STDERR_FILENO);
			ft_putstr_fd(strerror(errno), STDERR_FILENO);
			ft_putstr_fd("\n", STDERR_FILENO);
			return (1);
		}
		add_export(ft_strdup("PWD"), getcwd(NULL, 0), env_list);
	}
	return (0);
}
