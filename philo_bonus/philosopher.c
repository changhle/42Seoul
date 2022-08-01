#include "philosophers.h"

void	check_philo(t_info *info, t_philo *philo)
{
	int			i;
	long long	time;

	while (1)
	{
		i = 0;
		while (i < info->num_philos)
		{
			time = cur_time();
			if ((time - philo[i].last_eat) >= info->time_die)
			{
				info->die = 1;
				pthread_mutex_lock(&info->print);
				printf("%lld %d %s\n", time - info->start_time, philo[i].id, "died");
				pthread_mutex_unlock(&info->print);
				return ;
			}
			if (info->full_philo == info->num_philos)
				return ;
			i++;
		}
	}
}

void	take_fork(t_philo *philo)
{
	if (philo->id % 2)
	{
		pthread_mutex_lock(&philo->left->fork);
		print_state(philo, "has taken a fork");
		pthread_mutex_lock(&philo->right->fork);
		print_state(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(&philo->right->fork);
		print_state(philo, "has taken a fork");
		pthread_mutex_lock(&philo->left->fork);
		print_state(philo, "has taken a fork");
	}
}

int	philo_eating(t_philo *philo)
{
	take_fork(philo);
	philo->last_eat = cur_time();
	print_state(philo, "is eating");
	wait_time(philo->last_eat, philo->info->time_eat);
	philo->eat_count++;
	if (philo->eat_count == philo->info->num_eat)
		philo->info->full_philo++;
	pthread_mutex_unlock(&philo->right->fork);
	pthread_mutex_unlock(&philo->left->fork);
	if (philo->info->die || (philo->info->full_philo == philo->info->num_philos))
		return (1);
	return (0);
}

int	philo_sleeping(t_philo *philo)
{
	print_state(philo, "is sleeping");
	wait_time(cur_time(), philo->info->time_sleep);
	if (philo->info->die || (philo->info->full_philo == philo->info->num_philos))
		return (1);
	return (0);
}

int	philo_thinking(t_philo *philo)
{
	print_state(philo, "is thinking");
	usleep(1000);
	if (philo->info->die || (philo->info->full_philo == philo->info->num_philos))
		return (1);
	return (0);
}

void	*philo_thread(void *temp)
{
	t_philo	*philo;

	philo = (t_philo *)temp;
	if (philo->id % 2)
		usleep(1000);
	while (1)
	{
		if (philo_eating(philo))
			return (NULL);
		if (philo_sleeping(philo))
			return (NULL);
		if (philo_thinking(philo))
			return (NULL);
	}
}

int	philosopher(t_info *info, t_philo *philo)
{
	int	i;

	i = 0;
	info->start_time = cur_time();
	while (i < info->num_philos)
	{
		philo[i].last_eat = cur_time();
		if (pthread_create(&philo[i].thread, NULL, philo_thread, &philo[i]))
			return (1);
		i++;
	}
	check_philo(info, philo);
	i = 0;
	while (i < info->num_philos)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
	return (0);
}