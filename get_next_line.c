/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 14:47:43 by changhle          #+#    #+#             */
/*   Updated: 2021/12/09 15:07:22 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

char *get_next_line(int fd)
{
	char	*str;

	if (fd < 0 || 10 <= 0)
		return (NULL);
	str = ft_read_str(fd, str);
	if (!str)
		return (NULL);
	str = ft_get_newline(str);
	return (str);
}

int	main()
{
	int fd;
	char *str;

	fd = open("test.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("%s\n", str);
	str = get_next_line(fd);
	printf("%s\n", str);
}