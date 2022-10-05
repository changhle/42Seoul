/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeongin <ljeongin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:23:34 by ljeongin          #+#    #+#             */
/*   Updated: 2022/10/04 19:33:47 by ljeongin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_pipe(int pipefd[2])
{
	if (pipe(pipefd) < 0)
		ft_perror_exit("pipe() error");
}
