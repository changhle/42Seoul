/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 22:58:08 by changhle          #+#    #+#             */
/*   Updated: 2022/09/25 05:49:39 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "philosophers.h"

void	check_philo(t_info *info, t_philo *philo)
{
	int			i;

	while (1)
	{
		i = 0;
		while (i < info->num_philos)
		{
			if ((cur_time() - philo[i].last_eat) > info->time_die)
			{
				info->die = 1;
				pthread_mutex_lock(&info->print);
				printf("%lld %d %s\n", cur_time() - info->start_time,
					philo[i].id, "died");
				pthread_mutex_unlock(&info->print);
				return ;
			}
			if (info->full_philo == info->num_philos)
				return ;
			i++;
		}
		usleep(1000);
	}
}
