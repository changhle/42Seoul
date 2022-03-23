/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:47:01 by changhle          #+#    #+#             */
/*   Updated: 2022/03/22 18:19:48 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	s_send()

void	s_receive(int signo, siginfo_t *info, void *none)
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
			kill(info.si_pid, SIGUSR2);
			return ;
		}
		write(1, &c, 1);
		c = 0;
		kill(info.si_pid, SIGUSR1);
	}
	else
		c = c << 1;
}

int	main(void)
{
	struct sigaction s_sigaction;

	ft_putstr_fd("Server PID : ", 1);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	act.sa_flags =  SA_SIGINFO;
	act.sa_sigation = s_receive;
	sigaction(SIGUSR1, &act, 0);
	sigaction(SIGUSR2, &act, 0);
	while (1)
		pause();
	return (0);
}