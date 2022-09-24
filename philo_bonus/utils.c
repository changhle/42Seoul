/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 21:41:33 by changhle          #+#    #+#             */
/*   Updated: 2022/09/25 05:49:30 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <stdlib.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>
#include "philosophers.h"

int	ft_atoi(const char *str)
{
	unsigned long long	result;
	int					sign;

	sign = 1;
	while (*str == ' ' || *str == '\n' || *str == '\t'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (*str < 48 || *str > 57 || sign == -1)
		return (-1);
	result = 0;
	while (*str >= 48 && *str <= 57)
	{
		result = result * 10 + *str - 48;
		str++;
	}
	return (result * sign);
}

long long	cur_time(void)
{
	struct timeval	timeval;

	gettimeofday(&timeval, NULL);
	return (timeval.tv_sec * 1000 + timeval.tv_usec / 1000);
}

void	print_state(t_philo *philo, t_sem *sem, const char *str)
{
	sem_wait(sem->print);
	printf("%lld %d %s\n", cur_time() - philo->start_time,
		philo->id, str);
	sem_post(sem->print);
}

void	wait_time(long long start, long long delay)
{
	while (cur_time() - start <= delay)
		usleep(100);
}

int	ft_print_error(char *str)
{
	printf("%s\n", str);
	return (1);
}
