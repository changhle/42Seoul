/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:03:36 by changhle          #+#    #+#             */
/*   Updated: 2021/11/18 00:43:33 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	void	*ret;

	ret = dst;
	i = 0;
	if (dst > src && dst <= src + len)
	{
		dst += (len - 1);
		src += (len - 1);
		while (i < len)
		{
			*(char *)(dst - i) = *(char *)(src - i);
			i++;
		}
	}
	else
	{
		while (i < len)
		{
			*(char *)(dst + i) = *(char *)(src + i);
			i++;
		}
	}
	return (ret);
}
