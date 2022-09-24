#include <unistd.h>
#include <string.h>
#include <errno.h>

#include "libft.h"
#include "minishell.h"

static int cd_error(char *str)
{
	ft_putstr_fd("minishell: cd: ", STDOUT_FILENO);
	ft_putstr_fd(str, STDOUT_FILENO);
	ft_putstr_fd("\n", STDOUT_FILENO);
	return (1);
}

int	ft_cd(char **argv)
{
	int	argc;

	argc = 0;
	while (argv[argc])
		argc++;
	if (argc < 2)
		return (cd_error("no argument"));
	else if (argc > 2)
		return (cd_error("too many arguments"));
	if (chdir(argv[1]) == -1)
		return (cd_error(strerror(errno)));
	return (0);
}
