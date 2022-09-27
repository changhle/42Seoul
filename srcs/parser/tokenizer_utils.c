#include <stdlib.h>

#include "minishell.h"
#include "parser.h"
#include "libft.h"

void	init_token(char *line, t_token_info *info)
{
	info->buf_index = 0;
	info->quote = 0;
	info->buf_size = ft_strlen(line);
	info->buf = ft_calloc(info->buf_size, sizeof(char));
	if (!info->buf)
		exit(0);
}

char	set_quote(char quote, char c)
{
	if (quote == 0)
		quote = c;
	else if (quote == c)
		quote = 0;
	return (quote);
}

int	is_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	is_redirect(char *str)
{
	if (ft_strncmp("<", str, ft_strlen(str)) == 0
		|| ft_strncmp("\'<\'", str, ft_strlen(str)) == 0
		|| ft_strncmp("\"<\"", str, ft_strlen(str)) == 0)
		return (REDIR_IN);
	else if (ft_strncmp("<<", str, ft_strlen(str)) == 0
		|| ft_strncmp("\'<<\'", str, ft_strlen(str)) == 0
		|| ft_strncmp("\"<<\"", str, ft_strlen(str)) == 0)
		return (REDIR_IN_APPEND);
	else if (ft_strncmp(">", str, ft_strlen(str)) == 0
		|| ft_strncmp("\'>\'", str, ft_strlen(str)) == 0
		|| ft_strncmp("\">\"", str, ft_strlen(str)) == 0)
		return (REDIR_OUT);
	else if (ft_strncmp(">>", str, ft_strlen(str)) == 0
		|| ft_strncmp("\'>>\'", str, ft_strlen(str)) == 0
		|| ft_strncmp("\">>\"", str, ft_strlen(str)) == 0)
		return (REDIR_OUT_APPEND);
	return (0);
}
