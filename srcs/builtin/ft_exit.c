/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 09:57:00 by ljeongin          #+#    #+#             */
/*   Updated: 2022/09/30 18:55:43 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include "minishell.h"

int	ft_exit(int exit_value)
{
	write(STDOUT_FILENO, "exit\n", 5);
	exit(exit_value);
	return (0);
}
