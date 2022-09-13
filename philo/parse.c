/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 22:58:13 by changhle          #+#    #+#             */
/*   Updated: 2022/09/13 23:41:05 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	parse_man_opt(char **argv, t_info *info)
{
	info->num_philos = ft_atoi(argv[1]);
	info->time_die = ft_atoi(argv[2]);
	info->time_eat = ft_atoi(argv[3]);
	info->time_sleep = ft_atoi(argv[4]);
	info->num_eat = -1;
	info->full_philo = 0;
	info->die = 0;
	if ((info->num_philos == -1) || (info->time_die == -1)
		|| (info->time_eat == -1) || (info->time_sleep == -1))
		return (1);
	return (0);
}

static int	parse_add_opt(char **argv, t_info *info)
{
	info->num_eat = ft_atoi(argv[5]);
	if (info->num_eat == -1)
		return (1);
	return (0);
}

int	parse(int argc, char **argv, t_info *info)
{
	int	ret;

	if (argc == 5)
		return (parse_man_opt(argv, info));
	else if (argc == 6)
	{
		if (parse_man_opt(argv, info))
			return (1);
		return (parse_add_opt(argv, info));
	}
	else
		return (1);
}
