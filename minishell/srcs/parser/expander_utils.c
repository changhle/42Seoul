/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:42:38 by changhle          #+#    #+#             */
/*   Updated: 2022/10/11 11:13:55 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parser.h"
#include "libft.h"

void	init_expand(t_expand_info *info)
{
	info->i = 0;
	info->start = 0;
	info->quote = 0;
	info->buf = ft_strdup("");
	info->env_buf = NULL;
}

char	*comb_str(char *s1, char *s2)
{
	char	*ret;

	ret = ft_strjoin(s1, s2);
	ft_free((void **)&s1);
	if (s2)
		ft_free((void **)&s2);
	return (ret);
}
