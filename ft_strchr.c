/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 01:21:43 by changhle          #+#    #+#             */
/*   Updated: 2021/11/30 01:21:43 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (1)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		if (*s == '\0')
			break ;
		s++;
	}
	return (NULL);
}
