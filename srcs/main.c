#include <unistd.h>

#include "minishell.h"
#include "libft.h"

extern char	**environ;

static int	argc_error(int argc, char **argv)
{
	if (argc > 1)
	{
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		ft_putstr_fd(argv[1], STDERR_FILENO);
		ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
	}
	return (127);
}

int	main(int argc, char **argv)
{
	if (argc != 1)
		return (argc_error(argc, argv));
	printf_shell_banner();
	loop_readline(environ);
	return (SUCCESS);
}
