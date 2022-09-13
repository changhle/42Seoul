/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 21:41:13 by changhle          #+#    #+#             */
/*   Updated: 2022/09/12 21:41:14 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <semaphore.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#include "philosophers.h"

void	*check_ate(void	*temp)
{
	int		i;
	t_data	*data;

	data = (t_data *)temp;
	i = 0;
	while (i < data->info->num_philos)
	{
		sem_wait(data->sem->finish);
		i++;
	}
	kill(data->pid, SIGTERM);
	return (NULL);
}

int	observe(t_info *info, t_sem *sem, pid_t pid)
{
	t_data		data;
	pthread_t	checker;

	data.info = info;
	data.pid = pid;
	data.sem = sem;
	if (pthread_create(&checker, NULL, check_ate, &data))
		return (1);
	pthread_join(checker, NULL);
	return (0);
}

void	*check_philo(void *temp)
{
	long long	time;
	t_data		*data;

	data = (t_data *)temp;
	while (1)
	{
		time = cur_time();
		if (time - data->philo->last_eat > data->info->time_die)
		{
			sem_wait(data->sem->print);
			printf("%lld %d %s\n", time - data->philo->start_time,
				data->philo->id, "died");
			exit(0);
		}
		usleep(1000);
	}
}
