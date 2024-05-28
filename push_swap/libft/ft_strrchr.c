/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 01:22:53 by changhle          #+#    #+#             */
/*   Updated: 2022/06/26 16:33:50 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*ret;

	ret = NULL;
	while (1)
	{
		if (*s == (unsigned char)c)
			ret = (char *)s;
		if (*s == '\0')
			break ;
		s++;
	}
	return (ret);
}
