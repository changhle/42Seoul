/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 21:41:22 by changhle          #+#    #+#             */
/*   Updated: 2022/11/07 15:57:26 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include "philosophers.h"

static void	philo_eating(t_info *info, t_philo *philo, t_sem *sem)
{
	take_fork(philo, sem);
	philo->last_eat = cur_time();
	print_state(philo, sem, "is eating");
	wait_time(philo->last_eat, info->time_eat);
	philo->eat_count++;
	if (philo->eat_count >= info->num_eat)
		sem_post(sem->finish);
	realse_fork(sem);
}

static void	philo_sleeping(t_info *info, t_philo *philo, t_sem *sem)
{
	print_state(philo, sem, "is sleeping");
	wait_time(cur_time(), info->time_sleep);
}

static void	philo_thinking(t_info *info, t_philo *philo, t_sem *sem)
{
	print_state(philo, sem, "is thinking");
	usleep(1000);
}

static void	philo_process(t_info *info, t_philo *philo, t_sem *sem)
{
	t_data		data;
	pthread_t	checker;

	data.info = info;
	data.philo = philo;
	data.sem = sem;
	if (pthread_create(&checker, NULL, check_philo, &data))
		exit(1);
	while (1)
	{
		philo_eating(info, philo, sem);
		philo_sleeping(info, philo, sem);
		philo_thinking(info, philo, sem);
	}
}

int	philosophers(t_info *info, t_philo *philo, t_sem *sem)
{
	int			i;
	pid_t		*pid;
	long long	time;

	pid = malloc(sizeof(pid_t) * info->num_philos);
	if (!pid)
		return (ft_print_error("alloc error!"));
	i = 0;
	time = cur_time();
	while (i < info->num_philos)
	{
		init_philo(info, philo, time, i);
		pid[i] = fork();
		if (pid[i] == 0)
			philo_process(info, philo, sem);
		else if (pid[i] == -1)
			return (ft_print_error("fork error!"));
		i++;
	}
	monitor(info, sem, pid);
	free(pid);
	return (0);
}
