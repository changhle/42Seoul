#include <stdio.h>
#include <semaphore.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#include "philosophers.h"

void	*check_ate(void	*temp)
{
	int	i;
	t_ob	*data;

	data = (t_ob *)temp;
	// printf("%d\n", data->info->pid);
	i = 0;
	while (i < data->num_philos)
	{
		// printf("---------------------%d--------------\n", data->info->pid);
		sem_wait(data->finish);
		i++;
	}
	printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	kill(data->pid, SIGTERM);
	return (NULL);
}

int	observe(t_info *info, t_philo *philo, t_sem *sem, pid_t	pid)
{
	// t_data		data;
	pthread_t	checker;

	// data.info = info;
	// data.info->pid = pid;
	// data.philo = philo;
	// data.sem = sem;
	// data.pid = pid;
	// printf("---------==-----%d-%d-%d------------\n", pid, info->pid, data.info->pid);
	if (pthread_create(&checker, NULL, check_ate, &(t_ob){info->num_philos, pid, sem->finish}))
		return (1);
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
			printf("%lld %d %s\n", time - data->philo->start_time, data->philo->id, "died");
			exit(0);
		}
		usleep(1000);
	}
}