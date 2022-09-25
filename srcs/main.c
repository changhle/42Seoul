#include <stdio.h>

#include "minishell.h"
#include "libft.h"

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

static int	argc_error(int argc, char **argv)
{
	if (argc > 1)
		printf("minishell: %s: No such file or directory\n", argv[1]);
	return (127);
}

int	main(int argc, char **argv, char **envp)
{
	int			ret_value;
	t_env_list	*env;

	if (argc != 1)
		return (argc_error(argc, argv));
	init_env(envp, &env);
	printf_shell_banner();
	ret_value = loop_readline(envp);
	return (ret_value);
}
