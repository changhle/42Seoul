#include "minishell.h"
#include "libft.h"

void	free_env_list(t_env_list *env_list)
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

t_env_list	*add_env_node(t_env_list **env)
{
	t_env_list	*new;
	t_env_list	*tmp;

	tmp = *env;
	new = ft_malloc(sizeof(t_env_list));
	new->env = NULL;
	new->key = NULL;
	new->value = NULL;
	new->next = NULL;
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

void	init_env(char **envp, t_env_list **env)
{
	int			i;
	int			j;
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
