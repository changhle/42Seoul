/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeongin <ljeongin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 09:57:00 by ljeongin          #+#    #+#             */
/*   Updated: 2022/09/22 09:57:02 by ljeongin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include "minishell.h"

void	ft_exit(int exit_value)
{
	write(STDOUT_FILENO, "exit\n", 5);
	exit(exit_value);
}
