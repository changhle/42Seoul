/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 01:18:21 by changhle          #+#    #+#             */
/*   Updated: 2021/11/30 03:33:32 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*arr;

	i = 0;
	arr = NULL;
	arr = malloc(count * size);
	if (!arr)
		return (arr);
	while (i < count)
	{
		arr[i] = 0;
		i++;
	}
	return (arr);
}
