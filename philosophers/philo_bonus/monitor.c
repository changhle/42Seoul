/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 21:41:13 by changhle          #+#    #+#             */
/*   Updated: 2022/11/10 14:46:58 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <semaphore.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#include "philosophers.h"

static void	*check_ate(void	*temp)
{
	unsigned int	i;
	t_data			*data;

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

void	monitor(t_info *info, t_sem *sem, pid_t *pid)
{
	t_data		data;

	if (info->num_eat > 0)
	{
		data.info = info;
		data.pid = pid[0];
		data.sem = sem;
		pthread_create(&info->checker, NULL, check_ate, &data);
	}
	wait_process(info, sem, pid, info->num_philos);
}

void	*check_philo(void *temp)
{
	t_data		*data;

	data = (t_data *)temp;
	while (1)
	{
		sem_wait(data->sem->event);
		if (cur_time() - data->philo->last_eat > data->info->time_die)
		{
			sem_wait(data->sem->print);
			printf("%lld %d %s\n", cur_time() - data->philo->start_time,
				data->philo->id, "died");
			exit(0);
		}
		sem_post(data->sem->event);
		usleep(1000);
	}
}
