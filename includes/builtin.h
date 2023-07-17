/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:41:20 by changhle          #+#    #+#             */
/*   Updated: 2022/10/10 18:41:24 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

typedef struct s_env_list	t_env_list;

/*
**	builtin
*/
int			ft_pwd(void);
int			ft_exit(char **cmd);
int			ft_cd(char **argv, t_env_list **env_list);
int			ft_echo(char **argv);
int			ft_env(char **cmd, t_env_list **env_list);
int			ft_export(char **cmd, t_env_list **env_list);
int			ft_unset(char **cmd, t_env_list **env_list);

/*
**	export util
*/
void		add_export(char *key, char *value, t_env_list **env_list);
char		**copy_env_key(t_env_list **env_list);
void		sort_key(char **key);
char		*get_key(char *str);
char		*get_value(char *str);
void		remove_export(char *str, t_env_list **env_list);

#endif
