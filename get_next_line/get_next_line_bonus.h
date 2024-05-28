/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 16:13:08 by changhle          #+#    #+#             */
/*   Updated: 2022/09/16 04:05:42 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_lst
{
	int				fd;
	char			*str;
	struct s_lst	*next;
}	t_lst;

char	*get_next_line(int fd);
char	*ft_read_str(int fd, char *str);
char	*ft_get_str(char *str);
char	*ft_get_remain_str(char *str);
size_t	ft_strlen(char *s);
int		ft_isnewline(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);

#endif
