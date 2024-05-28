/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:42:41 by changhle          #+#    #+#             */
/*   Updated: 2022/10/11 11:13:33 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parser.h"
#include "libft.h"

#include <stdlib.h>

static void	buffer_join(char *str, t_expand_info *info)
{
	info->buf = comb_str(info->buf,
			ft_substr(str, info->start, info->i - info->start));
	info->start = info->i + 1;
}

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
}

static void	replace_token(t_token_list *token, t_expand_info *info)
{
	ft_free((void **)&token->token);
	if (info->buf)
		token->token = ft_strdup(info->buf);
	ft_free((void **)&info->buf);
}

static void	replace_env(char *token, t_env_list **env,
	t_expand_info *info)
{
	buffer_join(token, info);
	if ((token[info->i + 1] == '\'' || token[info->i + 1] == '\"')
		&& info->quote == 0)
	{
		info->start++;
		return ;
	}
	while (1)
	{
		if ((!ft_isalnum(token[info->i + 1])
				&& token[info->i + 1] != '_'
				&& token[info->i + 1] != '?')
			|| token[info->i] == '?')
		{
			info->env_buf = ft_substr(token, info->start,
					info->i - info->start + 1);
			info->buf = comb_str(info->buf, find_env(info->env_buf, env));
			info->start = info->i + 1;
			ft_free((void **)&info->env_buf);
			break ;
		}
		info->i++;
	}
}

void	expander(t_token_list **token_list, t_env_list **env)
{
	t_token_list	*tmp;
	t_expand_info	info;

	tmp = *token_list;
	while (tmp)
	{
		init_expand(&info);
		while (tmp->token[info.i])
		{
			if (tmp->token[info.i] == '\'' || tmp->token[info.i] == '\"')
			{
				if (info.quote == 0 || info.quote == tmp->token[info.i])
					buffer_join(tmp->token, &info);
				info.quote = set_quote(info.quote, tmp->token[info.i]);
			}
			if ((info.quote == 0 || info.quote == '\"')
				&& tmp->token[info.i] == '$')
				replace_env(tmp->token, env, &info);
			info.i++;
		}
		buffer_join(tmp->token, &info);
		replace_token(tmp, &info);
		tmp = tmp->next;
	}
}
