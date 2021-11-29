/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 20:03:06 by changhle          #+#    #+#             */
/*   Updated: 2021/11/22 02:00:23 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = 0;
	while (dstsize > dst_len + i + 1 && *src != '\0')
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + 1] = '\0';
	if (dstsize <= dst_len)
		dst_len = dstsize;
	return (dst_len + src_len);
}
