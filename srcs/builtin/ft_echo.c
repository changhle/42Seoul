#include <unistd.h>

#include "libft.h"
#include "minishell.h"

static void	print_arg(int argc, char **argv)
{
	int	i;
	int	flag;

	if (ft_iseq(argv[1], "-n"))
		flag = 1;
	else
		flag = 0;
	i = flag + 1;
	while (i < argc)
	{
		ft_putstr_fd(argv[i], STDOUT_FILENO);
		i++;
		if (i < argc)
			ft_putstr_fd(" ", STDOUT_FILENO);
	}
	if (flag == 0)
		ft_putstr_fd("\n", STDOUT_FILENO);
}

void	ft_echo(char **argv)
{
	int	i;
	int	argc;

	argc = 0;
	while (argv[argc])
		argc++;
	if (argc < 2)
		ft_putstr_fd("\n", STDOUT_FILENO);
	else
		print_arg(argc, argv);
}
