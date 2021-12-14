/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:09:22 by changhle          #+#    #+#             */
/*   Updated: 2021/12/14 21:57:38 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char *get_next_line(int fd)
{
	char			*str;
	static fd_list	lst;

	if (lst.fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	lst.str = ft_read_str(lst.fd, lst.str);
	if (!lst.str)
		return (NULL);
	str = ft_get_newline(lst.str);
	lst.str = ft_get_remain_str(lst.str);
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
	while (!ft_strchr(s_str, '\n') && bytes != 0)
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

char	*ft_get_newline(char *s_str)
{
	int		i;
	char	*newline;

	i = 0;
	if (!s_str[i])
		return (NULL);
	while (s_str[i] && s_str[i] != '\n')
		i++;
	newline = (char *)malloc(sizeof(char) * (i + 2));
	if (!newline)
		return (NULL);
	i = 0;
	while (s_str[i] && s_str[i] != '\n')
	{
		newline[i] = s_str[i];
		i++;
	}
	if (s_str[i] == '\n')
	{
		newline[i] = s_str[i];
		i++;
	}
	newline[i] = '\0';
	return (newline);
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
	i++;
	j = 0;
	while (s_str[i])
	{
		str[j] = s_str[i];
		i++;
		j++;
	}
	str[j] = '\0';
	free(s_str);
	return (str);
}

/*int	main()
{
	int fd;
	char *str;

	fd = open("test.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);	
	free(str);
}*/
