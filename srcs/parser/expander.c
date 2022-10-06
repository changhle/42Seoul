#include "minishell.h"
#include "parser.h"
#include "libft.h"

#include <stdio.h>
#include <stdlib.h>

static char	*find_env(char *str, t_env_list **env)
{
	t_env_list	*tmp;

	if (*str == '\0')
		return (ft_strdup("$"));
	else if (ft_iseq(str, "?"))
		return (ft_itoa(g_exit_status));
	tmp = *env;
	while (tmp)
	{
		if (ft_iseq(str, tmp->key))
			return (ft_strdup(tmp->value));
		tmp = tmp->next;
	}
	return (NULL);
	// return (ft_strdup(""));
}

static void	replace_env(char *token, t_env_list **env,
	t_expand_info *info)
{
	info->buf = comb_str(info->buf,
			ft_substr(token, info->start, info->index - info->start));
	info->start = info->index + 1;
	if ((token[info->index + 1] == '\''	|| token[info->index + 1] == '\"')
		&& info->quote == 0)
	{
		info->start++;
		return ;
	}
	while (1)
	{
		if (!ft_isalnum(token[info->index + 1])
			&& token[info->index + 1] != '_'
			&& token[info->index + 1] != '?')
		{
			info->env_buf = ft_substr(token, info->start,
					info->index - info->start + 1);
			info->buf = comb_str(info->buf, find_env(info->env_buf, env));
			info->start = info->index + 1;
			free(info->env_buf);
			break ;
		}
		info->index++;
	}
}

// char	*expander(char *line, t_env_list **env)
// {
// 	t_expand_info	info;

// 	init_expand(&info);
// 	while (line[info.index])
// 	{
// 		if (line[info.index] == '\''
// 			|| line[info.index] == '\"')
// 			info.quote = set_quote(info.quote, line[info.index]);
// 		if ((info.quote == 0 || info.quote == '\"')
// 			&& line[info.index] == '$')
// 			replace_env(line, env, &info);
// 		info.index++;
// 	}
// 	info.buf = comb_str(info.buf,
// 			ft_substr(line, info.start, info.index - info.start + 1));
// 	return (info.buf);
// }

void	expander(t_token_list **token_list, t_env_list **env)
{
	t_token_list	*tmp;
	t_expand_info	info;

	tmp = *token_list;
	while (tmp)
	{
		init_expand(&info);
		while (tmp->token[info.index])
		{
			if (tmp->token[info.index] == '\''
				|| tmp->token[info.index] == '\"')
				info.quote = set_quote(info.quote, tmp->token[info.index]);
			if ((info.quote == 0 || info.quote == '\"')
				&& tmp->token[info.index] == '$')
				replace_env(tmp->token, env, &info);
			info.index++;
		}
		info.buf = comb_str(info.buf,
			ft_substr(tmp->token, info.start, info.index - info.start + 1));
		ft_free((void **)&tmp->token);
		if (info.buf[0] == '\0')
			ft_free((void **)&info.buf);
		else
			tmp->token = info.buf;
		tmp = tmp->next;
	}
}
