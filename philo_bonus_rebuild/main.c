#include <stdlib.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "philosophers.h"

// static int	init_philo(t_info *info, t_philo **tmp)
// {
// 	int		i;
// 	t_philo *philo;

// 	philo = malloc(sizeof(t_philo) * info->num_philos);
// 	if (!philo)
// 		return (1);
// 	i = 0;
// 	while (i < info->num_philos)
// 	{
// 		philo[i].id = i + 1;
// 		philo[i].eat_count = 0;
// 		philo[i].is_dead = 0;
// 		i++;
// 	}
// 	*tmp = philo;
// 	return (0);
// }
void	init_philo(t_info *info, t_philo *philo, long long time, unsigned int i)
{
	philo->id = i + 1;
	philo->eat_count = 0;
	philo->start_time = time;
	philo->last_eat = time;
}

static int	init_sem(t_info *info, t_sem *sem)
{
	sem_unlink("lock");
	sem_unlink("fork");
	sem_unlink("print");
	sem_unlink("finish");
	sem_unlink("event");
	sem->lock = sem_open("lock", O_CREAT | O_EXCL, S_IRUSR | S_IWUSR, info->num_philos / 2);
	sem->fork = sem_open("fork", O_CREAT | O_EXCL, S_IRUSR | S_IWUSR, info->num_philos);
	sem->print = sem_open("print", O_CREAT | O_EXCL, S_IRUSR | S_IWUSR, 1);
	sem->finish = sem_open("finish", O_CREAT | O_EXCL, S_IRUSR | S_IWUSR, 0);
	sem->event = sem_open("event", O_CREAT | O_EXCL, S_IRUSR | S_IWUSR, 1);
	if (sem->lock == SEM_FAILED ||
		sem->fork == SEM_FAILED ||
		sem->print == SEM_FAILED ||
		sem->finish == SEM_FAILED ||
		sem->event == SEM_FAILED)
		return (1);
	return (0);
}

static void	destroy_sem(t_sem *sem)
{
	sem_unlink("lock");
	sem_unlink("fork");
	sem_unlink("print");
	sem_unlink("finish");
	sem_unlink("event");
	sem_close(sem->lock);
	sem_close(sem->fork);
	sem_close(sem->print);
	sem_close(sem->finish);
	sem_close(sem->event);
}

int	main(int argc, char **argv)
{
	t_info	info;
	t_sem	sem;
	t_philo	philo;

	if (parse(argc, argv, &info))
		return (1);
	// if (init_philo(&info, &philo))
	// 	return (1);
	if (init_sem(&info, &sem))
		return (1);
	if (philosopher(&info, &philo, &sem))
		return (1);
	// free(philo);
	destroy_sem(&sem);
	return (0);
}