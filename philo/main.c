/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 22:58:03 by changhle          #+#    #+#             */
/*   Updated: 2022/11/09 19:31:06 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "philosophers.h"

static t_philo	*init_philo(t_info *info, t_philo *philo)
{
	int	i;

	philo = malloc(sizeof(t_philo) * info->num_philos);
	if (!philo)
		return (NULL);
	i = 0;
	while (i < info->num_philos)
	{
		philo[i].id = i + 1;
		philo[i].left = &philo[(i + 1) % info->num_philos];
		philo[i].right = &philo[i];
		philo[i].eat_count = 0;
		philo[i].info = info;
		i++;
	}
	return (philo);
}

static int	init_fork_mutex(unsigned int num_philos, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < num_philos)
	{
		if (pthread_mutex_init(&philo[i].fork, NULL))
		{
			while (i > 0)
			{
				i--;
				pthread_mutex_destroy(&philo[i].fork);
			}
			return (1);
		}
		i++;
	}
	return (0);
}

static int	init_mutex(t_info *info, t_philo *philo)
{
	if (pthread_mutex_init(&info->print, NULL))
		return (1);
	if (pthread_mutex_init(&info->event, NULL))
	{
		pthread_mutex_destroy(&info->event);
		return (1);
	}
	if (init_fork_mutex(info->num_philos, philo))
	{
		pthread_mutex_destroy(&info->print);
		return (1);
	}
	return (0);
}

static void	destroy_mutex(t_info *info, t_philo *philo)
{
	int	i;

	pthread_mutex_destroy(&info->print);
	pthread_mutex_destroy(&info->event);
	i = 0;
	while (i < info->num_philos)
	{
		pthread_mutex_destroy(&philo[i].fork);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_info	info;
	t_philo	*philo;

	if (parse(argc, argv, &info))
		return (ft_print_error("arg error!"));
	philo = init_philo(&info, philo);
	if (!philo)
		return (ft_print_error("philo init error!"));
	if (init_mutex(&info, philo))
		return (ft_print_error("mutex init error!"));
	if (philosophers(&info, philo))
		return (ft_print_error("thread create error!"));
	destroy_mutex(&info, philo);
	free(philo);
	return (0);
}
