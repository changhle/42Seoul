#include "parser.h"
#include "libft.h"

#include <stdlib.h>

static char	*remove_quote_helper(char *str)
{
	t_expand_info	info;

	init_expand(&info);
	while (str[info.index])
	{
		if (((str[info.index] == '\'' || str[info.index] == '\"')
				&& info.quote == 0) || info.quote == str[info.index])
		{
			info.quote = set_quote(info.quote, str[info.index]);
			info.buf = comb_str(info.buf,
					ft_substr(str, info.start, info.index - info.start));
			info.start = info.index + 1;
		}
		info.index++;
	}
	info.buf = comb_str(info.buf,
			ft_substr(str, info.start, info.index - info.start));
	return (info.buf);
}

void	remove_quote(t_token_list **token)
{
	char			*buf;
	t_token_list	*tmp;

	tmp = *token;
	while (tmp)
	{
		buf = remove_quote_helper(tmp->token);
		free(tmp->token);
		tmp->token = buf;
		tmp = tmp->next;
	}
}
