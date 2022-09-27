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

char	*remove_quote(char *str)
{
	t_expand_info	info;

	init_expand(&info);
	while (str[info.index])
	{
		if (((str[info.index] == '\'' || str[info.index] == '\"')
			&& info.quote == 0) || info.quote == str[info.index])
		{
			info.quote = set_quote(info.quote, str[info.index]);
			info.buf = comb_str(info.buf, ft_substr(str, info.start, info.index - info.start));
			info.start = info.index + 1;
		}
		info.index++;
	}
	info.buf = comb_str(info.buf, ft_substr(str, info.start, info.index - info.start));
	return (info.buf);
}