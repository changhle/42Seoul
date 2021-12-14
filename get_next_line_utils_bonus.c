/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:09:15 by changhle          #+#    #+#             */
/*   Updated: 2021/12/14 19:04:44 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (1)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		if (*s == '\0')
			break ;
		s++;
	}
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}
/* 
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!src)
	{
		dst[i] = '\0';
		return (0);
	}
	if (dstsize > 0)
	{
		while (src[i] && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = 0;
	if (dstsize > dst_len + 1)
	{
		while (dstsize > dst_len + i + 1 && src[i])
		{
			dst[dst_len + i] = src[i];
			i++;
		}
		dst[dst_len + i] = '\0';
	}
	if (dstsize <= dst_len)
		dst_len = dstsize;
	return (dst_len + src_len);
}
 */
char	*ft_strjoin(char *s_str, char *s2)
{
	size_t	i;
	size_t	s1_len;
	size_t	s2_len;
	char	*str;

	if (!s2)
		return (NULL);
	s1_len = ft_strlen(s_str);
	s2_len = ft_strlen(s2);
	str = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < s1_len)
	{
		str[i] = s_str[i];
		i++;
	}
	i = 0;
	while (i < s2_len)
	{
		str[s1_len + i] = s2[i];
		i++;
	}
	str[s1_len + s2_len] = '\0';
	if (s_str)
		free(s_str);
	return (str);
}
