/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 21:41:27 by changhle          #+#    #+#             */
/*   Updated: 2022/11/11 13:19:52 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <semaphore.h>

typedef struct s_info
{
	unsigned int	num_philos;
	unsigned int	time_die;
	unsigned int	time_eat;
	unsigned int	time_sleep;
	unsigned int	num_eat;
	pthread_t		checker;
}	t_info;

typedef struct s_philo
{
	unsigned int	id;
	unsigned int	eat_count;
	long long		start_time;
	long long		last_eat;
}	t_philo;

typedef struct s_sem
{
	sem_t	*fork;
	sem_t	*lock;
	sem_t	*event;
	sem_t	*print;
	sem_t	*finish;
}	t_sem;

typedef struct s_data
{
	t_info	*info;
	t_philo	*philo;
	t_sem	*sem;
	pid_t	pid;
}	t_data;

int			parse(int argc, char **argv, t_info *info);
int			philosophers(t_info *info, t_philo *philo, t_sem *sem);
void		*check_philo(void *temp);
void		take_fork(t_philo *philo, t_sem *sem);
void		realse_fork(t_sem *sem);
void		init_philo(t_philo *philo, long long time, unsigned int i);
void		monitor(t_info *info, t_sem *sem, pid_t *pid);
void		wait_process(t_info *info, t_sem *sem, pid_t *pid,
				unsigned int process_num);

int			ft_atoi(const char *str);
long long	cur_time(void);
void		print_state(t_philo *philo, t_sem *sem, const char *str);
void		wait_time(long long start, long long delay);
int			ft_print_error(char *str);

#endif