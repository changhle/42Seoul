/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 22:58:08 by changhle          #+#    #+#             */
/*   Updated: 2022/11/09 19:35:02 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "philosophers.h"

static int	check_all_full(t_info *info)
{
	int	full;

	full = 0;
	pthread_mutex_lock(&info->event);
	if (info->full_philo >= info->num_philos)
		full = 1;
	pthread_mutex_unlock(&info->event);
	return (full);
}

static int	check_time_die(t_info *info, t_philo philo)
{
	int	ret;

	ret = 0;
	pthread_mutex_lock(&info->event);
	if ((cur_time() - philo.last_eat) > info->time_die)
		ret = 1;
	pthread_mutex_unlock(&info->event);
	return (ret);
}

void	check_philo(t_info *info, t_philo *philo)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < info->num_philos)
		{
			if (check_time_die(info, philo[i]))
			{
				pthread_mutex_lock(&info->event);
				info->die = 1;
				pthread_mutex_unlock(&info->event);
				pthread_mutex_lock(&info->print);
				printf("%lld %d %s\n", cur_time() - info->start_time,
					philo[i].id, "died");
				pthread_mutex_unlock(&info->print);
				return ;
			}
			if (check_all_full(info) == 1)
				return ;
			i++;
		}
		usleep(1000);
	}
}
