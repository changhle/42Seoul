/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ito.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 16:32:34 by changhle          #+#    #+#             */
/*   Updated: 2021/11/22 03:05:55 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numlen(int n)
{
	int	len;

	if (n == 0)
		return (1);
	else if (n > 0)
		len = 1;
	else if (n == -2147483648)
		return (11);
	else
	{
		n *= -1;
		len = 2;
	}
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				len;
	unsigned int	p_n;

	len = numlen(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
		*str = 48;
	else if (n < 0)
	{
		*str = '-';
		n *= -1;
	}
	p_n = n;
	while (p_n > 0)
	{
		str[len - 1] = p_n % 10 + 48;
		p_n /= 10;
		len--;
	}
	return (str);
}
