#include <stdlib.h>
#include <unistd.h>

#include "minishell.h"
#include "libft.h"

static char	**copy_env_key(t_env_list **env_list)
{
	int			n;
	char		**key;
	t_env_list	*tmp;

	tmp = *env_list;
	n = 0;
	while (tmp)
	{
		tmp = tmp->next;
		n++;
	}
	key = ft_malloc(sizeof(char **) * (n + 1));
	tmp = *env_list;
	n = 0;
	while (tmp)
	{
		key[n] = tmp->key;
		tmp = tmp->next;
		n++;
	}
	key[n] = NULL;
	return (key);
}

static void	sort_key(char **key)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (key[i + 1])
	{
		j = i + 1;
		while (key[j])
		{
			if (ft_memcmp(key[i], key[j], ft_strlen(key[i]) + 1) > 0)
			{
				tmp = key[i];
				key[i] = key[j];
				key[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

static void	print_export(char **key, t_env_list **env_list)
{
	int			i;
	t_env_list	*tmp;

	i = 0;
	while (key[i])
	{
		tmp = *env_list;
		while (tmp)
		{
			if (ft_iseq(key[i], tmp->key))
			{
				ft_putstr_fd("declare -x ", STDOUT_FILENO);
				ft_putstr_fd(tmp->key, STDOUT_FILENO);
				if (tmp->value)
				{
					ft_putstr_fd("=\"", STDOUT_FILENO);
					ft_putstr_fd(tmp->value, STDOUT_FILENO);
					ft_putstr_fd("\"", STDOUT_FILENO);
				}
				ft_putstr_fd("\n", STDOUT_FILENO);
			}
			tmp = tmp->next;
		}
		i++;
	}
}

static void	add_export(char *str, t_env_list **env_list)
{
	int			i;
	t_env_list	*node;

	node = add_env_node(env_list);
	if (ft_strchr(str, '='))	
	{
		i = 0;
		while (str[i])
		{
			if (str[i] == '=')
				break;
			i++;
		}
		node->key = ft_substr(str, 0, i);
		node->value = ft_substr(str, i + 1, ft_strlen(str) - i - 1);
	}
	else
		node->key = ft_strdup(str);
}

int	ft_export(char **cmd, t_env_list **env_list)
{
	int			i;
	char		**key;

	if (!(*env_list))
		return (0);
	i = 0;
	if (!cmd[1])
	{
		key = copy_env_key(env_list);
		if (key[1])
			sort_key(key);
		print_export(key, env_list);
		free(key);
	}
	else
	{
		while (cmd[i])
			add_export(cmd[i++], env_list);
	}
	return (0);
}
