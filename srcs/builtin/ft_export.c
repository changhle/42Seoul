#include <stdlib.h>
#include <unistd.h>

#include "minishell.h"
#include "libft.h"

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

static int	is_valid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isalpha(str[i]) && str[i] != '_' && str[i] != '=')
		{
			ft_putstr_fd("minishell: export: `", STDERR_FILENO);
			ft_putstr_fd(str, STDERR_FILENO);
			ft_putstr_fd("': not a valid identifier\n", STDERR_FILENO);
			return (1);
		}
		i++;
	}
	return (0);
}

static void	add_export(char *key, char *value, t_env_list **env_list)
{
	t_env_list	*node;

	if (value)
		remove_export(key, env_list);
	else
	{
		node = *env_list;
		while (node)
		{
			if (ft_iseq(key, node->key))
				return ;
			node = node->next;
		}
	}
	node = add_env_node(env_list);
	node->key = key;
	node->value = value;
}

int	ft_export(char **cmd, t_env_list **env_list)
{
	int			i;
	int			ret_value;
	char		**key;

	i = 1;
	ret_value = 0;
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
		{
			ret_value = is_valid(cmd[i]);
			if (!ret_value)
				add_export(get_key(cmd[i]), get_value(cmd[i]), env_list);
			i++;
		}
	}
	return (ret_value);
}
