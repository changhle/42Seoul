/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 22:58:18 by changhle          #+#    #+#             */
/*   Updated: 2022/09/25 05:49:41 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	take_fork(t_philo *philo)
{
	if (philo->id % 2)
	{
		pthread_mutex_lock(&philo->left->fork);
		print_state(philo, "has taken a fork");
		pthread_mutex_lock(&philo->right->fork);
		print_state(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(&philo->right->fork);
		print_state(philo, "has taken a fork");
		pthread_mutex_lock(&philo->left->fork);
		print_state(philo, "has taken a fork");
	}
}

void	realse_fork(t_philo *philo)
{
	if (philo->id % 2)
	{
		pthread_mutex_unlock(&philo->left->fork);
		pthread_mutex_unlock(&philo->right->fork);
	}
	else
	{
		pthread_mutex_unlock(&philo->right->fork);
		pthread_mutex_unlock(&philo->left->fork);
	}
}
