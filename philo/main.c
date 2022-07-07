#include "philosophers.h"

int	init_philo_fork(t_val *val, int argc)
{
	int	i;

	pthread_mutex_init(&val->print, NULL);
	val->philo_fork = malloc(sizeof(pthread_mutex_t) * val->num_of_philos);
	if (!val->philo_fork)
		return (1);
	i = 0;
	while (i < val->num_of_philos)
	{
		pthread_mutex_init(&val->philo_fork[i], NULL);
		i++;
	}
	return (0);
}

int	init_val(t_val *val, int argc, char **argv)
{
	val->num_of_philos = ft_atoi(argv[1]);
	val->time_to_die = ft_atoi(argv[2]);
	val->time_to_eat = ft_atoi(argv[3]);
	val->time_to_sleep = ft_atoi(argv[4]);
	if (val->time_to_die < 0 || val->time_to_eat < 0
		|| val->time_to_sleep < 0 || val->num_of_philos < 0)
		return (1);
	if (argc == 6)
	{
		val->must_eat = ft_atoi(argv[5]);
		if (val->must_eat < 0)
			return (1);
	}
	val->die = 0;
	val->finish = 0;
	val->start_time = cur_time();
	return (0);
}

int	init_philo(t_philo *philo, t_val *val)
{
	int	i;

	// philo = malloc(sizeof(t_philo) * val->num_of_philos);
	// if (!philo)
	// 	return (1);
	i = 0;
	while (i < val->num_of_philos)
	{
		philo[i].philo_num = i + 1;
		philo[i].val = val;
		philo[i].last_time = cur_time();
		philo[i].eat_count = 0;
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		ret;
	t_val	val;
	t_philo	*philo;

	if (argc != 5 && argc != 6)
		return (0);
	memset(&val, 0, sizeof(t_val));
	ret = init_val(&val, argc, argv);
	if (ret)
		return (0);
	ret = init_philo_fork(&val, argc);
	if (ret)
		return (0);
	philo = malloc(sizeof(t_philo) * val.num_of_philos);
	ret = init_philo(philo, &val);
	if (ret)
		return (0);
	// printf("prev philo\n");
	ret = philosopher(philo, &val);
	// printf("next philo\n");
	if (ret)
		return (0);
}