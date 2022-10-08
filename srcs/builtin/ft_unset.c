#include <stdlib.h>
#include <unistd.h>

#include "minishell.h"
#include "builtin.h"
#include "libft.h"

static	int	print_error(char *str)
{
	ft_putstr_fd("minishell: unset: `", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd("': not a valid identifier\n", STDERR_FILENO);
	return (1);
}

static int	is_valid(char *str)
{
	int	i;

	if (!ft_isalpha(str[0]) && str[0] != '_')
		return (print_error(str));
	i = 1;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && !ft_isalpha(str[i]) && str[i] != '_')
			return (print_error(str));
		i++;
	}
	return (0);
}

void	remove_export(char *str, t_env_list **env_list)
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
	if (!tmp)
		return ;
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
	int	ret_value;

	i = 1;
	ret_value = 0;
	while (cmd[i])
	{
		ret_value = is_valid(cmd[i]);
		remove_export(cmd[i++], env_list);
	}
	return (ret_value);
}
