void	philo_process(t_val *val, t_philo *philo)
{
	t_val	*val;
	t_philo	*philo;

	philo = temp;
	val = philo->val;
	while (!val->die)
	{
		if (philo->philo_num % 2)
			usleep(1000);
		else
			usleep(500);
		eating(val, philo);
		if (val->must_eat == philo->eat_count)
		{
			val->finish++;
			break;
		}
		print_philo(val, philo->philo_num, "is sleeping");
		wait_time(val, val->time_to_sleep);
		print_philo(val, philo->philo_num, "is thinking");
	}
}