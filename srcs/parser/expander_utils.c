#include "minishell.h"
#include "parser.h"
#include "libft.h"

#include <stdlib.h>

void	init_expand(t_expand_info *info)
{
	info->index = 0;
	info->start = 0;
	info->quote = 0;
	info->buf = ft_strdup("");
	info->env_buf = NULL;
}

char	*comb_str(char *s1, char *s2)
{
	char	*ret;

	ret = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (ret);
}
