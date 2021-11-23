/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 19:38:44 by changhle          #+#    #+#             */
/*   Updated: 2021/11/18 00:43:00 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*arr;

	i = 0;
	arr = malloc(count * size);
	if (!arr)
		return (arr);
	while (i < count)
	{
		arr[i] = 0;
		i++;
	}
	return ((void *)arr);
}
