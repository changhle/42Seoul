/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeongin <ljeongin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 13:03:36 by ljeongin          #+#    #+#             */
/*   Updated: 2022/10/10 18:38:01 by ljeongin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_dup2(int fd1, int fd2)
{
	if (fd1 == -1)
		return ;
	if (dup2(fd1, fd2) < 0)
		ft_perror_exit("dup2() error");
	ft_close(fd1);
}
