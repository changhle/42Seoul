/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 03:17:44 by changhle          #+#    #+#             */
/*   Updated: 2021/11/22 02:29:52 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen(char const *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

static int	check_set(char c, char const *set)
{
	while (*set != '\0')
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

static char	*ft_strdup(char const *s, int start, int len)
{
	char	*str;
	int		i;

	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[i + start];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len;
	int		i;
	char	*str;

	len = ft_strlen(s1);
	i = 0;
	while (i < len)
	{
		if (!check_set(s1[i], set))
			break ;
		i++;
	}
	if (i == len)
		return (ft_strdup(s1, 0, 0));
	while (len > 0)
	{
		if (!check_set(s1[len - 1], set))
			break ;
		len--;
	}
	str = ft_strdup(s1, i, len - i);
	return (str);
}
