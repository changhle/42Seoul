/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:47:04 by changhle          #+#    #+#             */
/*   Updated: 2022/03/12 05:07:27 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send(int pid, char *str)
{
	int	i;

	while (1)
	{
		i = 7;
		while (i >= 0)
		{
			if ((*str >> i) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			i--;
			usleep(100);
		}
		if (!(*str))
			break ;
		str++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (0);
	ft_putstr_fd("Client PID : ", 1);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	send(ft_atoi(argv[1]), argv[2]);
	return (0);
}