#include <stdio.h>

#include "minishell.h"
#include "libft.h"

static int	argc_error(int argc, char **argv)
{
	if (argc > 1)
		printf("minishell: %s: No such file or directory\n", argv[1]);
	return (127);
}

int	main(int argc, char **argv, char **envp)
{
	int			ret_value;

	if (argc != 1)
		return (argc_error(argc, argv));
	printf_shell_banner();
	ret_value = loop_readline(envp);
	return (ret_value);
}
