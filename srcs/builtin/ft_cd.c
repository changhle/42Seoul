#include <unistd.h>
#include <string.h>
#include <errno.h>

#include "libft.h"
#include "minishell.h"

int	ft_cd(char **cmd)
{
	if (cmd[1])
	{
		if (chdir(cmd[1]) == -1)
		{
			ft_putstr_fd("minishell: cd: ", STDERR_FILENO);
			ft_putstr_fd(strerror(errno), STDERR_FILENO);
			ft_putstr_fd("\n", STDERR_FILENO);
			return (1);
		}
	}
	return (0);
}
