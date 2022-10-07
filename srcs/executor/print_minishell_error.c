#include "executor.h"
#include "libft.h"

#include <errno.h>
#include <unistd.h>
#include <string.h>

void	print_minishell_error(char *str, char *desc, int err_num)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	if (str)
	{
		ft_putstr_fd(str, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
	}
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
