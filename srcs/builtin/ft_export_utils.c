#include <stdlib.h>

#include "minishell.h"
#include "libft.h"

char	**copy_env_key(t_env_list **env_list)
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

void	sort_key(char **key)
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

char	*get_key(char *str)
{
	int		i;
	char	*key;

	if (ft_strchr(str, '='))
	{
		i = 0;
		while (str[i])
		{
			if (str[i] == '=')
				break ;
			i++;
		}
		key = ft_substr(str, 0, i);
	}
	else
		key = ft_strdup(str);
	return (key);
}

char	*get_value(char *str)
{
	int		i;
	char	*key;

	key = NULL;
	if (ft_strchr(str, '='))
	{
		i = 0;
		while (str[i])
		{
			if (str[i] == '=')
				break ;
			i++;
		}
		key = ft_substr(str, i + 1, ft_strlen(str) - i - 1);
	}
	return (key);
}
