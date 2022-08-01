#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

typedef struct s_info
{
	unsigned int	num_philos;
	unsigned int	time_die;
	unsigned int	time_eat;
	unsigned int	time_sleep;
	unsigned int	num_eat;
	unsigned int	full_philo;
	unsigned int	die;
	unsigned int	finish;
	long long		start_time;
	pthread_mutex_t	print;
	pthread_mutex_t	event;
} t_info;

typedef struct s_philo
{
	unsigned int	id;
	unsigned int	eat_count;
	long long		last_eat;
	pthread_mutex_t	fork;
	pthread_t		thread;
	struct s_philo	*left;
	struct s_philo	*right;
	struct s_info	*info;
} t_philo;

void check_philo(t_info *info, t_philo *philo);
long long cur_time(void);
void destroy_mutex(t_info *info, t_philo *philo);
int ft_atoi(const char *str);
int init_fork_mutex(unsigned int num_philos, t_philo *philo);
int init_mutex(t_info *info, t_philo *philo);
int init_philo(t_info *info, t_philo *philo);
int main(int argc, char **argv);
int parse(int argc, char **argv, t_info *info);
int parse_add_opt(char **argv, t_info *info);
int parse_man_opt(char **argv, t_info *info);
int philo_eating(t_philo *philo);
int philo_sleeping(t_philo *philo);
int philo_thinking(t_philo *philo);
void *philo_thread(void *temp);
int philosopher(t_info *info, t_philo *philo);
void print_error(void);
void print_state(t_philo *philo, char *str);
void take_fork(t_philo *philo);
void	wait_time(long long start, long long delay);

#endif