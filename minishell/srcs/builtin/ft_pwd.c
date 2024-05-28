/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:28:16 by changhle          #+#    #+#             */
/*   Updated: 2023/07/17 21:12:44 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

#include "minishell.h"
#include "libft.h"

int	ft_pwd(void)
{
	char	*cur_path;

	cur_path = getcwd(NULL, 0);
	if (!cur_path)
	{
		ft_perror("getcwd() error");
		return (FAILURE);
	}
	printf("%s\n", cur_path);
	ft_free((void **)&cur_path);
	return (SUCCESS);
}
