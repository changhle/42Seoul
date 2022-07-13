#include "philosophers.h"

long long	cur_time(void)
{
	struct timeval	timeval;

	gettimeofday(&timeval, NULL);
	return ((timeval.tv_sec * 1000) + (timeval.tv_usec / 1000));
}

void	wait_time(t_val *val, long long start, long long delay)
{
	// int	time;

	// time = cur_time();
	// if (!val->die)
	// 	usleep(delay * 1000);
	// long long	start;
	long long	now;

	// start = cur_time();
	while (!(val->die))
	{
		now = cur_time();
		if ((now - start) >= delay)
			break ;
		usleep(10);
	}
}

void	print_philo(t_val *val, int	philo_num, char *str)
{
	long long	time;

	pthread_mutex_lock(&val->print);
	time = cur_time();
	if (!val->die)
		printf("%lld %d %s\n", time - val->start_time, philo_num, str);
	pthread_mutex_unlock(&val->print);
}

void	eating(t_val *val, t_philo *philo)
{
	int	left;
	int	right;

	left = philo->philo_num + val->num_of_philos;
	right = philo->philo_num + val->num_of_philos - 1;
	if (philo->philo_num % 2)
		ft_swap(&left, &right);
	// {
	// 	usleep(1000);
	// }
	// else
	// 	usleep(500);
	pthread_mutex_lock(&val->philo_fork[right % val->num_of_philos]);
	print_philo(val, philo->philo_num, "has taken a fork");
	pthread_mutex_lock(&val->philo_fork[left % val->num_of_philos]);
	print_philo(val, philo->philo_num, "has taken a fork");
	print_philo(val, philo->philo_num, "is eating");
	philo->last_time = cur_time();
	philo->eat_count++;
	wait_time(val, philo->last_time, val->time_to_eat);
	pthread_mutex_unlock(&val->philo_fork[right % val->num_of_philos]);
	pthread_mutex_unlock(&val->philo_fork[left % val->num_of_philos]);
}

void	*philo_thread(void *temp)
{
	t_val	*val;
	t_philo	*philo;

	philo = temp;
	val = philo->val;
	// printf("prev sleep\n");
	// sleep(100);
	// printf("next sleep\n");
	if (philo->philo_num % 2)
		usleep(1000);
	// else
	// 	usleep(500);
	while (!val->die)
	{
		eating(val, philo);
		if (val->must_eat == philo->eat_count)
		{
			val->finish++;
			break;
		}
		print_philo(val, philo->philo_num, "is sleeping");
		wait_time(val, cur_time(), val->time_to_sleep);
		print_philo(val, philo->philo_num, "is thinking");
	}
}

void	check_die_finish(t_val *val, t_philo *philo)
{
	int			i;
	long long	time;

	while (!val->die && val->finish != val->num_of_philos)
	{
		i = 0;
		// printf("prev while\n");
		while (i < val->num_of_philos)
		{
			// printf("prev inner\n");
			time = cur_time();
			if (time - philo[i].last_time >= val->time_to_die)
			{
				val->die = 1;
				printf("%lld %d %s\n", time - val->start_time, philo[i].philo_num, "died");
				// print_philo(val, philo[i].philo_num, "died");
				break ;
			}
			// printf("next inner\n");
			i++;
		}
		// printf("next while\n");
	}
}

int	philosopher(t_philo *philo, t_val *val)
{
	int	i;

	i = 0;
	while (i < val->num_of_philos)
	{
		philo[i].last_time = cur_time();
		if (pthread_create(&philo[i].thread, NULL, philo_thread, &philo[i]))
			return (1);
		i++;
		// usleep(1);
	}
	// int	i;
	// int	j;

	// j = 0;
	// while (j < 2)
	// {
	// 	i = 0;
	// 	while (i < val->num_of_philos)
	// 	{
	// 		philo[i].last_time = cur_time();
	// 		if (philo->philo_num % 2 == j)
	// 			pthread_create(&philo[i].thread, NULL, philo_thread, &philo[i]);
	// 		i++;
	// 		// usleep(1);
	// 	}
	// 	j++;
	// }
	// printf("prev die\n");
	check_die_finish(val, philo);
	// printf("next die\n");
	i = 0;
	while (i < val->num_of_philos)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
	i = 0;
	while (i < val->num_of_philos)
	{
		pthread_mutex_destroy(&val->philo_fork[i]);
		i++;
	}
	pthread_mutex_destroy(&val->print);
	return (0);
}