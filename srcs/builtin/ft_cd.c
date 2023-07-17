#include <unistd.h>
#include <string.h>
#include <errno.h>

#include "minishell.h"
#include "builtin.h"
#include "libft.h"

static int	change_dir(char *dir, t_env_list **env_list)
{
	char	*old_pwd;

	old_pwd = getcwd(NULL, 0);
	if (chdir(dir) == -1)
	{
		ft_putstr_fd("minishell: cd: ", STDERR_FILENO);
		ft_putstr_fd(dir, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putstr_fd(strerror(errno), STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
		return (1);
	}
	add_export(ft_strdup("OLDPWD"), old_pwd, env_list);
	add_export(ft_strdup("PWD"), getcwd(NULL, 0), env_list);
	return (0);
}

static char	*get_home_dir(t_env_list **env_list)
{
	t_env_list	*tmp;

	tmp = *env_list;
	while (tmp)
	{
		if (ft_iseq(tmp->key, "HOME"))
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}

int	ft_cd(char **cmd, t_env_list **env_list)
{
	char	*dir;

	if (cmd[1])
		dir = cmd[1];
	else
		dir = get_home_dir(env_list);
	if (dir)
		return (change_dir(dir, env_list));
	else
		ft_putstr_fd("minishell: cd: HOME not set\n", STDERR_FILENO);
	return (1);
}
