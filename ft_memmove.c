/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 01:20:50 by changhle          #+#    #+#             */
/*   Updated: 2021/11/30 01:20:50 by changhle         ###   ########.fr       */
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
