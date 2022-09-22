/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeongin <ljeongin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:28:16 by ljeongin          #+#    #+#             */
/*   Updated: 2022/09/20 14:13:46 by ljeongin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

#include "minishell.h"

void	ft_pwd(void)
{
	char	*cur_path;

	cur_path = getcwd(NULL, 1);
	printf("%s\n", cur_path);
	free(cur_path);
}
