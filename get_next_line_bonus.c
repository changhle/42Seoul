/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:09:22 by changhle          #+#    #+#             */
/*   Updated: 2022/09/16 04:09:12 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_lst	*search_fd(t_lst **lst, int fd)
{
	t_lst	*new;
	t_lst	*tmp;

	tmp = *lst;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	if (!tmp)
	{
		new = malloc(sizeof(t_lst));
		new->fd = fd;
		new->str = NULL;
		new->next = *lst;
		*lst = new;
	}
	return (*lst);
}

void	remove_node(t_lst **lst, int fd)
{
	t_lst	*tmp;
	t_lst	*prev;

	tmp = *lst;
	prev = NULL;
	while (tmp)
	{
		if (tmp->fd == fd)
			break ;
		prev = tmp;
		tmp = tmp->next;
	}
	if (!prev)
		*lst = tmp->next;
	else
		prev->next = tmp->next;
	free(tmp->str);
	free(tmp);
}

char	*get_next_line(int fd)
{
	char			*str;
	t_lst			*s_lst;
	static t_lst	*lst;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	s_lst = search_fd(&lst, fd);
	s_lst->str = ft_read_str(fd, s_lst->str);
	if (!s_lst->str || !s_lst->str[0])
	{
		remove_node(&lst, fd);
		return (NULL);
	}
	str = ft_get_str(s_lst->str);
	s_lst->str = ft_get_remain_str(s_lst->str);
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
