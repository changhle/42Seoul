#include "parser.h"
#include "libft.h"

static void	add_token(t_token_list *node, t_token_list **token,
	t_token_info *info)
{
	t_token_list	*new;
	t_token_list	*tmp;

	// if (node->token[0] != '\0' && info->buf[0] == '\0')
	// 	return ;
	tmp = *token;
	new = ft_malloc(sizeof(t_token_list));
	new->token_type = node->token_type;
	new->token = NULL;
	if (node->token)
		new->token = ft_strdup(info->buf);
	new->next = NULL;
	if (!tmp)
		*token = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	if (node->token)
	{
		ft_memset(info->buf, 0, info->buf_size);
		info->buf_index = 0;
	}
}

void	word_split_helper(t_token_list *node, t_token_list **token)
{
	int				i;
	t_token_info	info;

	if (!node->token)
	{
		add_token(node, token, &info);
		return ;
	}
	// if (!node->token || node->token[0] == '\0')
	// {
	// 	// add_token(node, token, &info);
	// 	return ;
	// }
	i = 0;
	init_token(node->token, &info);
	while (node->token[i])
	{
		if (node->token[i] == '\'' || node->token[i] == '\"')
			info.quote = set_quote(info.quote, node->token[i]);
		if (is_space(node->token[i]) && info.quote == 0)
			add_token(node, token, &info);
		else if ((!is_space(node->token[i]) && info.quote == 0)
			|| info.quote != 0)
		{
			info.buf[info.buf_index++] = node->token[i];
			info.buf[info.buf_index] = '\0';
		}
		i++;
	}
	if (node->token[i] == '\0')
		add_token(node, token, &info);
	ft_free((void **)&info.buf);
}
#include <stdio.h>
t_token_list	*word_split(t_token_list **token_list)
{
	t_token_list	*token;
	t_token_list	*tmp;
	// t_token_list	*tmp_free;

	token = NULL;
	tmp = *token_list;
	while (tmp)
	{
		// tmp_free = tmp;
		word_split_helper(tmp, &token);
		tmp = tmp->next;
	}
	return (token);
}