#include <semaphore.h>
#include "philosophers.h"

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