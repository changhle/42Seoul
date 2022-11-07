/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 21:41:18 by changhle          #+#    #+#             */
/*   Updated: 2022/11/07 16:03:59 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <semaphore.h>
#include <signal.h>
#include <sys/wait.h>
#include "philosophers.h"

void	init_philo(t_info *info, t_philo *philo, long long time, unsigned int i)
{
	philo->id = i + 1;
	philo->eat_count = 0;
	philo->start_time = time;
	philo->last_eat = cur_time();
}

void	take_fork(t_philo *philo, t_sem *sem)
{
	sem_wait(sem->lock);
	sem_wait(sem->fork);
	print_state(philo, sem, "has taken a fork");
	sem_wait(sem->fork);
	print_state(philo, sem, "has taken a fork");
}

void	realse_fork(t_sem *sem)
{
	sem_post(sem->fork);
	sem_post(sem->fork);
	sem_post(sem->lock);
}

void	wait_process(t_info *info, pid_t *pid)
{
	int	i;
	int	status;

	i = 0;
	waitpid(0, &status, 0);
	while (i < info->num_philos)
	{
		kill(pid[i], SIGTERM);
		waitpid(pid[i], &status, 0);
		i++;
	}
}
