/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeongin <ljeongin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 13:04:52 by ljeongin          #+#    #+#             */
/*   Updated: 2022/10/02 13:55:08 by ljeongin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void	ft_perror(char *str)
{
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(strerror(errno), STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}

void	ft_perror_exit(char *str)
{
	ft_perror(str);
	exit(errno);
}
