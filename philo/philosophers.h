#ifndef PHIOSOPHERS_H
# define PHIOSOPHERS_H

# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

typedef struct s_val
{
	int				num_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				die;
	int				finish;
	long long		start_time;
	pthread_mutex_t	*philo_fork;
	pthread_mutex_t	print;
} t_val;

typedef struct s_philo
{
	t_val		*val;
	pthread_t	thread;
	int			philo_num;
	int			eat_count;
	long long	last_time;
} t_philo;

void		ft_swap(int *a, int *b);
int			philosopher(t_philo *philo, t_val *val);
long long	cur_time(void);
int			ft_atoi(const char *str);

#endif