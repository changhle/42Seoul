#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
// # include <pthread.h>
// # include <sys/time.h>
// # include <stdlib.h>
// # include <unistd.h>
// # include <string.h>
# include <semaphore.h>
// # include <sys/stat.h>
// # include <fcntl.h>
// # include <sys/wait.h>

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
	pid_t			pid;
} t_info;

typedef struct s_philo
{
	unsigned int	id;
	unsigned int	eat_count;
	unsigned int	is_dead;
	long long		start_time;
	long long		last_eat;
} t_philo;

typedef struct s_sem
{
	sem_t	*fork;
	sem_t	*lock;
	sem_t	*print;
	sem_t	*finish;
	sem_t	*event;
} t_sem;

typedef struct s_data
{
	t_info	*info;
	t_philo	*philo;
	t_sem	*sem;
	pid_t	pid;
} t_data;

typedef struct s_ob
{
	unsigned int	num_philos;
	pid_t			pid;
	sem_t			*finish;
} t_ob;

int parse(int argc, char **argv, t_info *info);
int	philosopher(t_info *info, t_philo *philo, t_sem *sem);
void	*check_philo(void *temp);
void	take_fork(t_philo *philo, t_sem *sem);
void	realse_fork(t_sem *sem);
void	init_philo(t_info *info, t_philo *philo, long long time, unsigned int i);
// int	observe(t_info *info, t_philo *philo, t_sem *sem, pid_t pid);
// int	observe(t_ob *data);
int	observe(t_info *info, t_sem *sem, pid_t pid);

int ft_atoi(const char *str);
long long cur_time(void);
void	print_state(t_philo *philo, t_sem *sem, const char *str);
void	wait_time(long long start, long long delay);

// void	*check_philo(void *temp);
// void destroy_mutex(t_info *info, t_philo *philo);
// int init_fork_mutex(unsigned int num_philos, t_philo *philo);
// int init_mutex(t_info *info, t_philo *philo);
// int	init_philo(t_info *info, t_philo *philo, sem_t *sem_print, sem_t *sem_event);
// int parse_add_opt(char **argv, t_info *info);
// int parse_man_opt(char **argv, t_info *info);
// int philo_eating(t_info *info, t_philo *philo, sem_t *sem_fork);
// int philo_sleeping(t_info *info, t_philo *philo, sem_t *sem_fork);
// int	philo_thinking(t_info *info, t_philo *philo, sem_t *sem_fork);
// void *philo_thread(void *temp);
// void print_error(void);
// void	print_state(t_info *info, t_philo *philo, char *str);
// void	take_fork(t_info *info, t_philo *philo, sem_t *sem_fork);
// void	wait_time(long long start, long long delay);

#endif