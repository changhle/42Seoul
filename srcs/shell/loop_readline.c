#include <unistd.h>
#include <stdlib.h>
#include <readline/history.h>

#include "minishell.h"
#include "libft.h"

int	g_exit_status;

static int	write_exit_without_newline(void)
{
	// write(STDOUT_FILENO, "\x1b[1A", 4);
	// write(STDOUT_FILENO, "\033[11C", 5);
	write(STDOUT_FILENO, "exit\n", 5);
	exit(SUCCESS);
}

static t_bool	is_valid_line(char	**line)
{
	char	*tmp;

	tmp = *line;
	*line = ft_strtrim(*line, " \t\r\v\f\n");
	ft_free((void **)&tmp);
	if (ft_strlen(*line))
		return (TRUE);
	return (FALSE);
}

void	loop_readline(char **envp)
{
	int				ret_value;
	char			*line;
	t_env_list		*env_list;
	t_parsed_list	*parsed_list;

	env_list = NULL;
	init_env(envp, &env_list);
	while (1)
	{
		line = read_shell_line("\001\033[0;34m\002minishell$\001\033[0m\002 ");
		if (!line)
			write_exit_without_newline();
		if (is_valid_line(&line))
		{
			add_history(line);
			ret_value = parse(line, &parsed_list, &env_list);
			if (ret_value == SUCCESS)
				execute(parsed_list, &env_list);
		}
		ft_free((void **)&line);
	}
	free_env_list(env_list);
}
