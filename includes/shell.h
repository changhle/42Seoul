/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:41:32 by changhle          #+#    #+#             */
/*   Updated: 2022/10/10 18:41:33 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

typedef struct s_parsed_list	t_parsed_list;
typedef struct s_env_list		t_env_list;

int			parse(
				char *line,
				t_parsed_list **parsed_head,
				t_env_list **env_list
				);

void		execute(t_parsed_list *parsed__list, t_env_list **env_list);

char		*read_shell_line(char *prompt);

void		init_env(char **envp, t_env_list **env);
t_env_list	*add_env_node(t_env_list **env);
void		free_env_list(t_env_list *env_list);

void		free_parsed_list(t_parsed_list **parsed_list);

#endif
