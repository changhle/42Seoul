#include "parser.h"
#include "libft.h"

static void	add_token(t_token_list *node, t_token_list **token,
	t_token_info *info)
{
	t_token_list	*new;
	t_token_list	*tmp;

	if (node->token && info->buf[0] == '\0')
		return ;
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
	t_token_info	info;

	if (!node->token)
	{
		add_token(node, token, &info);
		return ;
	}
	init_token(node->token, &info);
	while (*node->token)
	{
		if (*node->token == '\'' || *node->token == '\"')
			info.quote = set_quote(info.quote, *node->token);
		if (is_space(*node->token) && info.quote == 0)
			add_token(node, token, &info);
		else if ((!is_space(*node->token) && info.quote == 0)
			|| info.quote != 0)
		{
			info.buf[info.buf_index++] = *node->token;
			info.buf[info.buf_index] = '\0';
		}
		node->token++;
	}
	add_token(node, token, &info);
	ft_free((void **)&info.buf);
}

t_token_list	*word_split(t_token_list **token_list)
{
	t_token_list	*token;
	t_token_list	*tmp;

	token = NULL;
	tmp = *token_list;
	while (tmp)
	{
		word_split_helper(tmp, &token);
		tmp = tmp->next;
	}
	return (token);
}