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

static void	free_env_list(t_env_list *env_list)
{
	t_env_list	*tmp;

	while (env_list)
	{
		tmp = NULL;
		if (env_list->next)
			tmp = env_list->next;
		ft_free((void **)&env_list->env);
		ft_free((void **)&env_list->key);
		ft_free((void **)&env_list->value);
		ft_free((void **)&env_list);
		env_list = tmp;
	}
}

static t_env_list	*add_env_node(t_env_list **env)
{
	t_env_list	*new;
	t_env_list	*tmp;

	tmp = *env;
	new = ft_malloc(sizeof(t_env_list));
	if (!tmp)
		*env = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (new);
}

static void	init_env(char **envp, t_env_list **env)
{
	int	i;
	int	j;
	t_env_list	*node;

	i = 0;
	while (envp[i])
	{
		node = add_env_node(env);
		node->env = ft_strdup(envp[i]);
		j = 0;
		while (envp[i][j])
		{
			if (envp[i][j] == '=')
			{
				envp[i][j] = '\0';
				node->key = ft_strdup(envp[i]);
				node->value = ft_strdup(&envp[i][j + 1]);
				break ;
			}
			j++;
		}
		i++;
	}
}

static int	write_exit_without_newline(void)
{
	// write(STDOUT_FILENO, "\x1b[1A", 4);
	// write(STDOUT_FILENO, "\033[11C", 5);
	write(STDOUT_FILENO, "exit\n", 5);
	return (SUCCESS);
}

int	loop_readline(char **envp)
{
	int				ret_value;
	char			*line;
	t_env_list		*env_list;
	t_parsed_list	*parsed_list;

	ret_value = 0;
	env_list = NULL;
	init_env(envp, &env_list);
	while (1)
	{
		line = read_shell_line("\033[0;34mminishell$\033[0m ");
		if (!line)
			return (write_exit_without_newline());
		if (ft_strlen(line))
		{
			add_history(line);
			ret_value = parse(line, &parsed_list, &env_list);
			ft_free((void **)&line);
			if (ret_value == SUCCESS)
				ret_value = execute(parsed_list, &env_list);
		}
	}
	free_env_list(env_list);
	return (ret_value);
}
