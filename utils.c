/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 01:17:51 by changhle          #+#    #+#             */
/*   Updated: 2022/06/26 09:47:30 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <unistd.h>

void	print_error(int errno)
{
	if (errno == 1)
		write(2, "Error\n", 6);
	else if (errno == 2)
		write(2, "Alloc Error\n", 12);
	exit(1);
}

void	free_all(t_info *info)
{
	t_node	*temp;

	while (info->a_top)
	{
		temp = info->a_top;
		info->a_top = temp->next;
		free(temp);
		temp = NULL;
	}
	while (info->cmd_top)
	{
		temp = info->cmd_top;
		info->cmd_top = temp->next;
		free(temp);
		temp = NULL;
	}
	free(info);
}

void	check_overlap(t_info *info)
{
	t_node	*temp_i;
	t_node	*temp_j;

	temp_i = info->a_top;
	while (temp_i)
	{
		temp_j = temp_i->next;
		while (temp_j)
		{
			if (temp_i->content == temp_j->content)
				print_error(1);
			temp_j = temp_j->next;
		}
		temp_i = temp_i->next;
	}
}

int	ft_strcmp(char *str1, char *str2)
{
	while ((*str1 && *str2) && (*str1 == *str2))
	{
		str1++;
		str2++;
	}
	return (*(unsigned char *)str1 - *(unsigned char *)str2);
}

long long	ft_atoll(const char *str)
{
	unsigned long long	result;
	int					sign;

	sign = 1;
	result = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		result = result * 10 + (*str - 48);
		str++;
	}
	if (*str)
		return (2147483648);
	if ((sign == 1 && result > 2147483647)
		|| (sign == -1 && result > 2147483648))
		return (2147483648);
	return (result * sign);
}
