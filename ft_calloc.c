/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 01:18:21 by changhle          #+#    #+#             */
/*   Updated: 2021/12/06 18:39:33 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*arr;

	if (count * size == 0)
		return (NULL);
	i = 0;
	arr = malloc(count * size);
	if (!arr)
		return (arr);
	ft_bzero(arr, count * size);
	return (arr);
}
