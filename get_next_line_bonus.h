/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 16:13:08 by changhle          #+#    #+#             */
/*   Updated: 2021/12/15 01:58:11 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>

typedef struct fd_list
{
    int	        	fd;
    char	        *str;
	struct fd_list	*next;
}	fd_list;

char	*get_next_line(int fd);
char	*ft_read_str(int fd, char *str);
char	*ft_get_str(char *str);
char	*ft_get_remain_str(char *str);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s_str, char *s2);

#endif
