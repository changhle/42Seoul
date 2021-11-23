/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 18:09:21 by changhle          #+#    #+#             */
/*   Updated: 2021/11/19 20:12:16 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static int	count_word(char const *s, char c)
{
	int	word;
	int	cnt;

	cnt = 0;
	word = 0;
	while (1)
	{
		if (word == 0 && *s != c)
		{
			word = 1;
			cnt++;
		}
		else if (word == 1 && (*s == c || *s == '\0'))
			word = 0;
		if (*s == '\0')
			break ;
		s++;
	}
	return (cnt);
}

static char	*ft_strdup(char *str, int len)
{
	char	*s;
	char	*ret_s;

	s = (char *)malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	ret_s = s;
	while (len > 0)
	{
		*(s++) = *(str++);
		len--;
	}
	*s = '\0';
	return (ret_s);
}

static void	fill_word(char const *s, char **arr, char c)
{
	int		i;
	int		word;
	char	*start;

	i = 0;
	word = 0;
	while (1)
	{
		if (word == 0 && *s != c)
		{
			word = 1;
			start = (char *)s;
		}
		else if (word == 1 && (*s == c || *s == '\0'))
		{
			word = 0;
			arr[i++] = ft_strdup(start, s - start);
		}
		if (*s == '\0')
			break ;
		s++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**arr;

	arr = (char **)malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!arr)
		return (NULL);
	fill_word(s, arr, c);
	return (arr);
}

int main()
{
	char **arr;
	arr = ft_split("       		 ", ' ');
	for(int i = 0; i < ; i++)
		printf("%s\n", arr[i]);
}
