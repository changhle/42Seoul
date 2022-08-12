/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:09:22 by changhle          #+#    #+#             */
/*   Updated: 2021/12/15 16:11:51 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char		*str;
	static char	*s_str[OPEN_MAX];

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	s_str[fd] = ft_read_str(fd, s_str[fd]);
	if (!s_str[fd])
		return (NULL);
	str = ft_get_str(s_str[fd]);
	s_str[fd] = ft_get_remain_str(s_str[fd]);
	return (str);
}

char	*ft_read_str(int fd, char *s_str)
{
	int		bytes;
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes = 1;
	while (!ft_isnewline(s_str, '\n') && bytes != 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes] = '\0';
		s_str = ft_strjoin(s_str, buffer);
	}
	free(buffer);
	return (s_str);
}

char	*ft_get_str(char *s_str)
{
	int		i;
	char	*str;

	i = 0;
	if (!s_str[i])
		return (NULL);
	while (s_str[i] && s_str[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (s_str[i])
	{
		str[i] = s_str[i];
		i++;
		if (s_str[i - 1] == '\n')
			break ;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_get_remain_str(char *s_str)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (s_str[i] && s_str[i] != '\n')
		i++;
	if (!s_str[i])
	{
		free(s_str);
		return (NULL);
	}
	str = (char *)malloc(BUFFER_SIZE * sizeof(char));
	if (!str)
		return (NULL);
	j = 0;
	while (s_str[++i])
	{
		str[j] = s_str[i];
		j++;
	}
	str[j] = '\0';
	free(s_str);
	return (str);
}
