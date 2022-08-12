/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 16:27:20 by changhle          #+#    #+#             */
/*   Updated: 2022/05/19 13:16:19 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_isnewline(char *s, int c)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == (unsigned char)c)
			return (1);
		s++;
	}
	return (0);
}

size_t	ft_gnl_strlen(char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_gnl_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	s1_len;
	size_t	s2_len;
	char	*str;

	s1_len = ft_gnl_strlen(s1);
	s2_len = ft_gnl_strlen(s2);
	str = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = -1;
	while (++i < s1_len)
		str[i] = s1[i];
	i = -1;
	while (++i < s2_len)
		str[s1_len + i] = s2[i];
	str[s1_len + s2_len] = '\0';
	if (s1)
		free(s1);
	return (str);
}
