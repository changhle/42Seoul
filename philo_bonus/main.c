/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 21:41:01 by changhle          #+#    #+#             */
/*   Updated: 2022/09/12 21:41:02 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <semaphore.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "philosophers.h"

static int	init_sem(t_info *info, t_sem *sem)
{
	sem_unlink("lock");
	sem_unlink("fork");
	sem_unlink("print");
	sem_unlink("finish");
	sem->lock = sem_open("lock", O_CREAT | O_EXCL, S_IRUSR | S_IWUSR,
			info->num_philos / 2);
	sem->fork = sem_open("fork", O_CREAT | O_EXCL, S_IRUSR | S_IWUSR,
			info->num_philos);
	sem->print = sem_open("print", O_CREAT | O_EXCL, S_IRUSR | S_IWUSR, 1);
	sem->finish = sem_open("finish", O_CREAT | O_EXCL, S_IRUSR | S_IWUSR, 0);
	if (sem->lock == SEM_FAILED
		|| sem->fork == SEM_FAILED
		|| sem->print == SEM_FAILED
		|| sem->finish == SEM_FAILED)
		return (1);
	return (0);
}

static void	destroy_sem(t_sem *sem)
{
	sem_unlink("lock");
	sem_unlink("fork");
	sem_unlink("print");
	sem_unlink("finish");
	sem_close(sem->lock);
	sem_close(sem->fork);
	sem_close(sem->print);
	sem_close(sem->finish);
}

int	main(int argc, char **argv)
{
	t_info	info;
	t_sem	sem;
	t_philo	philo;

	if (parse(argc, argv, &info))
		return (1);
	if (init_sem(&info, &sem))
		return (1);
	if (philosopher(&info, &philo, &sem))
		return (1);
	destroy_sem(&sem);
	return (0);
}
