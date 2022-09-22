#include <stdio.h>
#include <stdlib.h>

#include "minishell.h"
#include "parser.h"
#include "libft.h"

static void	add_token(t_token_list **token, t_token_info *info)
{
	t_token_list	*new;
	t_token_list	*tmp;

	if (info->buf[0] == '\0')
		return ;
	tmp = *token;
	new = malloc(sizeof(t_token_list));
	if (ft_strncmp("|", info->buf, ft_strlen(info->buf)) == 0)
		new->token_type = PIPE;
	else if (is_redirect(info->buf))
		new->token_type = REDIRECT;
	else
		new->token_type = WORD;
	info->buf[info->buf_index] = '\0';
	new->token = ft_strdup(info->buf);
	new->next = NULL;
	if (!(*token))
		*token = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	ft_memset(info->buf, 0, info->buf_size);
	info->buf_index = 0;
}

static void	buf_check(t_token_list **token, t_token_info *info, char c)
{
	if (ft_strchr("><", c) && info->buf[0] == c)
	{
		info->buf[info->buf_index++] = c;
		add_token(token, info);
	}
	else if (!ft_strchr("><|", info->buf[0]) && !ft_strchr("><|", c))
		info->buf[info->buf_index++] = c;
	else
	{
		add_token(token, info);
		info->buf[info->buf_index++] = c;
	}
}

void	tokenizer(char *line, t_token_list **token)
{
	t_token_info	info;

	init_token(line, &info);
	while (*line)
	{
		if ((*line == '\'' || *line == '\"') && info.quote == 0
			|| *line == info.quote)
			info.quote = set_quote(info.quote, *line);
		else if (is_space(*line) && info.quote == 0)
			add_token(token, &info);
		else if ((!is_space(*line) && info.quote == 0) || info.quote != 0)
		{
			if (info.quote == 0)
				buf_check(token, &info, *line);
			else
				info.buf[info.buf_index++] = *line;
		}
		line++;
	}
	add_token(token, &info);
	free(info.buf);
}
