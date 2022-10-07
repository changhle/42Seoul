#include <unistd.h>

#include "libft.h"
#include "minishell.h"

static int	ft_isflag(char *str)
{
	int	i;

	if (str[0] != '-')
		return (0);
	i = 1;
	while (str[i])
	{
		if (str[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

static void	print_arg(char **cmd)
{
	int	i;
	int	flag;

	if (ft_isflag(cmd[1]))
		flag = 1;
	else
		flag = 0;
	i = flag + 1;
	while (cmd[i])
	{
		ft_putstr_fd(cmd[i], STDOUT_FILENO);
		i++;
		if (cmd[i])
			ft_putstr_fd(" ", STDOUT_FILENO);
	}
	if (flag == 0)
		ft_putstr_fd("\n", STDOUT_FILENO);
}

int	ft_echo(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
		i++;
	if (i < 2)
		ft_putstr_fd("\n", STDOUT_FILENO);
	else
		print_arg(cmd);
	return (0);
}
