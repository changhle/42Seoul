#include "minishell.h"
#include "executor.h"
#include "libft.h"

#include <stddef.h>

static char	**get_envp(t_env_list *env_list)
{
	t_env_list	*index;
	char		**ret;
	size_t		cnt;
	size_t		i;

	index = env_list;
	cnt = 0;
	while (index)
	{
		cnt++;
		index = index->next;
	}
	ret = ft_malloc(sizeof(char *) * (cnt + 1));
	i = 0;
	while (i < cnt)
	{
		ret[i++] = env_list->env;
		env_list = env_list->next;
	}
	ret[i] = NULL;
	return (ret);
}

void	init_exec_info(t_exec_info *exec_info, t_env_list *env_list)
{
	exec_info->is_first = TRUE;
	exec_info->is_last = FALSE;
	exec_info->process_cnt = 0;
	exec_info->env_head = env_list;
	exec_info->envp = get_envp(env_list);
}
