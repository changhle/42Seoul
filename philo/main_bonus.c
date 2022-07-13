#include "philosophers_bonus.h"

int	main(int argc, char **argv)
{
	int		i;
	int		ret;
	pid_t	*pid;
	t_val	val;	
	t_philo	*philo;
	sem_t	philo_fork;

	if (argc != 5 && argc != 6)
		return (0);
	ret = init_val(&val, argc, argv);
	if (ret)
		return (0);
	sem_init(philo_fork, 0, val.num_of_philos);
	pid = malloc(sizeof(pid_t) * val.num_of_philos);
	if (!pid)
		return (0);
	i = 0;
	while (i < val.num_of_philos)
	{
		pid[i] = fork();
		if (pid == 0)
			philo_process();
		i++;
	}
	i = 0;
	while (i < val.num_of_philos)
	{
		
	}
}