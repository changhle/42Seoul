#include <unistd.h>
#include <readline/history.h>

#include "minishell.h"
#include "libft.h"

/********** TO-DO **********/

/*
	expand environment variables(ex: $USER)
	ex)
	[ bash$ echo $USER   ] should be [ ljeongin ]
	[ bash$ echo "$USER" ] should be [ ljeongin ]
	[ bash# echo '$USER' ] should be [ '$USER'  ] -> does not interpret
*/

static void	write_exit_without_newline(void)
{
	write(STDOUT_FILENO, "\x1b[1A", 4);
	write(STDOUT_FILENO, "\033[11C", 5);
	write(STDOUT_FILENO, "exit\n", 5);
}

int	loop_readline(char **envp)
{
	int				ret_value;
	t_parsed_list	*parsed_list;
	char			*line;

	while (1)
	{
		line = read_shell_line("\033[0;34mminishell$\033[0m ");
		if (!line)
		{
			write_exit_without_newline();
			break ;
		}
		if (ft_strlen(line))
			add_history(line);
		ret_value = parse(line, &parsed_list);
		ft_free((void **)&line);
		if (ret_value == SUCCESS)
			ret_value = execute(parsed_list, envp);
	}
	return (ret_value);
}
