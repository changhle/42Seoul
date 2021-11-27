/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 20:38:05 by changhle          #+#    #+#             */
/*   Updated: 2021/11/19 18:07:10 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_strlen(char const *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	char			*ret_str;
	unsigned int	s_len;

	s_len = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	ret_str = str;
	if (s != 0 && s_len > start && len != 0)
	{
		while (len > 0)
		{
			*(str++) = s[start++];
			len--;
		}
	}
	*str = '\0';
	return (ret_str);
}
