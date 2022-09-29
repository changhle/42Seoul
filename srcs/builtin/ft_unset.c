#include <stdlib.h>

#include "minishell.h"
#include "libft.h"

static void	remove_export(char *str, t_env_list **env_list)
{
	t_env_list	*tmp;
	t_env_list	*prev;

	tmp = *env_list;
	prev = NULL;
	while (tmp)
	{
		if (ft_iseq(str, tmp->key))
			break ;
		prev = tmp;
		tmp = tmp->next;
	}
	if (!prev)
		*env_list = tmp->next;
	else
		prev->next = tmp->next;
	free(tmp->key);
	if (tmp->value)
		free(tmp->value);
	free(tmp);
}

int	ft_unset(char **cmd, t_env_list **env_list)
{
	int	i;

	if (!(*env_list))
		return (0);
	i = 1;
	while (cmd[i])
		remove_export(cmd[i++], env_list);
	return (0);
}
