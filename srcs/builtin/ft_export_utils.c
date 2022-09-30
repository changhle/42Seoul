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

char	**get_key(char *str)
{
	int		i;
	char	**key;

	key = ft_malloc(sizeof(char **) * 3);
	key[0] = ft_strdup("unset");
	if (ft_strchr(str, '='))
	{
		i = 0;
		while (str[i])
		{
			if (str[i] == '=')
				break;
			i++;
		}
		key[1] = ft_substr(str, 0, i);
	}
	else
		key[1] = ft_strdup(str);
	key[2] = NULL;
	return (key);
}
