/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 01:23:03 by changhle          #+#    #+#             */
/*   Updated: 2021/11/30 01:23:03 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	char			*ret_str;
	unsigned int	s_len;

	s_len = ft_strlen(s);
	if (s != 0 && s_len > start && len != 0)
	{
		str = (char *)malloc(sizeof(char) * (len + 1));
		if (!str)
			return (NULL);
		ret_str = str;
		while (len > 0)
		{
			*(str++) = s[start++];
			len--;
		}
	}
	else
		return (malloc(0));
	*str = '\0';
	return (ret_str);
}
