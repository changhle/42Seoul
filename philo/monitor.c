/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 22:58:08 by changhle          #+#    #+#             */
/*   Updated: 2022/09/13 22:58:09 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "philosophers.h"

void	check_philo(t_info *info, t_philo *philo)
{
	int			i;
	long long	time;

	while (1)
	{
		i = 0;
		while (i < info->num_philos)
		{
			time = cur_time();
			if ((time - philo[i].last_eat) >= info->time_die)
			{
				info->die = 1;
				pthread_mutex_lock(&info->print);
				printf("%lld %d %s\n", time - info->start_time,
					philo[i].id, "died");
				pthread_mutex_unlock(&info->print);
				return ;
			}
			if (info->full_philo == info->num_philos)
				return ;
			i++;
		}
	}
}
