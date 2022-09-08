#include <sys/time.h>
#include <stdlib.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>
#include "philosophers.h"

static int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	unsigned long long	result;
	int					sign;

	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (!ft_isdigit(*str))
		return (-1);
	result = 0;
	while (ft_isdigit(*str))
	{
		result = result * 10 + *str - 48;
		str++;
	}
	return (result * sign);
}

long long	cur_time(void)
{
	struct timeval	timeval;

	gettimeofday(&timeval, NULL);
	return (timeval.tv_sec * 1000 + timeval.tv_usec / 1000);
}

void	print_state(t_philo *philo, t_sem *sem, const char *str)
{
	sem_wait(sem->print);
	printf("%lld %d %s\n", cur_time() - philo->start_time,
		philo->id, str);
	sem_post(sem->print);
}

void	wait_time(long long start, long long delay)
{
	while (cur_time() - start <= delay)
		usleep(100);
}