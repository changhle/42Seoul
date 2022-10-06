#include "executor.h"
#include "libft.h"

#include <errno.h>
#include <unistd.h>
#include <string.h>

t_bool	is_builtin(char *command)
{
	if (!command)
		return (FALSE);
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

void	print_minishell_error(char *str, char *desc, int err_num)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	if (desc)
		ft_putstr_fd(desc, STDERR_FILENO);
	else
		ft_putstr_fd(strerror(errno), STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	if (err_num)
		g_exit_status = err_num;
	else
		g_exit_status = errno;
}
