/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeongin <ljeongin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 13:47:07 by ljeongin          #+#    #+#             */
/*   Updated: 2022/08/08 09:59:08 by ljeongin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_backup_list
{
	int						fd;
	char					*backup;
	struct s_backup_list	*next;
}				t_backup_list;

typedef struct s_context
{
	char	*line;
	char	*ret;
}				t_context;

char			*get_next_line(int fd);
char			*gnl_read_join(t_backup_list *here);
void			gnl_split_line(t_context *ubox, t_backup_list *here);
t_backup_list	*gnl_search_add_list(t_backup_list **head, int fd);
void			gnl_del_list(t_backup_list **head, t_backup_list *cur);
size_t			gnl_strlen(const char *s);
char			*gnl_strchr(const char *s, int c);
char			*gnl_strdup(const char *s);
char			*gnl_substr(char const *s, unsigned int start, size_t len);
char			*gnl_strjoin(char *line, char *buf);

#endif
