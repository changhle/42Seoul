#include <unistd.h>
#include <stdio.h>

#include "minishell.h"
#include "libft.h"

static void	print_env(t_env_list **env_list)
{
	t_env_list	*tmp;

	tmp = *env_list;
	while (tmp)
	{
		if (tmp->value)
		{
			ft_putstr_fd(tmp->key, STDOUT_FILENO);
			ft_putstr_fd("=", STDOUT_FILENO);
			ft_putstr_fd(tmp->value, STDOUT_FILENO);
			ft_putstr_fd("\n", STDOUT_FILENO);
		}
		tmp = tmp->next;
	}
}

int	ft_env(char **cmd, t_env_list **env_list)
{
	if (!(*env_list))
		return (0);
	if (!cmd[1])
		print_env(env_list);
	else
	{
		ft_putstr_fd("env: ", STDERR_FILENO);
		ft_putstr_fd(cmd[1], STDERR_FILENO);
		ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
		return (1);
	}
	return (0);
}
