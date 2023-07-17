/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeongin <ljeongin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:28:16 by ljeongin          #+#    #+#             */
/*   Updated: 2022/10/10 09:21:30 by ljeongin         ###   ########.fr       */
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
