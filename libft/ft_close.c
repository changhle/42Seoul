/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeongin <ljeongin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 13:01:16 by ljeongin          #+#    #+#             */
/*   Updated: 2022/10/02 20:18:12 by ljeongin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_close(int fd)
{
	if (fd < 3)
		return ;
	if (close(fd) < 0)
		ft_perror_exit("close() error");
}
