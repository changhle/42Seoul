/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:47:01 by changhle          #+#    #+#             */
/*   Updated: 2022/03/11 16:49:17 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	receive(int signo)
{
	static int	i = 0;
	static char	c = 0;

	if (signo == SIGUSR1)
		c = c | 1;
	if (i++ == 7)
	{
		i = 0;
		if (!c)
		{
			write(1, &c, 1);
			write(1, "\n", 1);
			return ;
		}
		write(1, &c, 1);
		c = 0;
	}
	else
		c = c << 1;
}

int	main(void)
{
	ft_putstr_fd("Server PID : ", 1);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	signal(SIGUSR1, receive);
	signal(SIGUSR2, receive);
	while (1)
		pause();
	return (0);
}