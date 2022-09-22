/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeongin <ljeongin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:56:14 by ljeongin          #+#    #+#             */
/*   Updated: 2022/01/10 16:39:25 by ljeongin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	count_len(int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		len = 1;
	if (n < 0)
		len++;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*ret;
	size_t			len;
	size_t			i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = count_len(n);
	i = len;
	ret = malloc(sizeof(char) * len + 1);
	if (!ret)
		return (NULL);
	if (n < 0)
	{
		n *= -1;
		ret[0] = '-';
		len--;
	}
	ret[i] = '\0';
	while (len-- > 0)
	{
		i--;
		ret[i] = n % 10 + '0';
		n = n / 10;
	}
	return (ret);
}
