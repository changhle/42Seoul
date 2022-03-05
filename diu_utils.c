/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diu_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 22:11:46 by changhle          #+#    #+#             */
/*   Updated: 2022/03/04 22:11:55 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbr_len(long nbr)
{
	int				len;
	unsigned int	u_nbr;

	if (nbr > 0)
		len = 0;
	else
	{
		nbr *= -1;
		len = 1;
	}
	u_nbr = (unsigned int)nbr;
	while (u_nbr > 0)
	{
		u_nbr /= 10;
		len++;
	}
	return (len);
}

void	ft_putnbr(long n)
{
	char	c;

	if (n < 0)
		n = n * -1;
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		c = '0' + n % 10;
		write(1, &c, 1);
	}
	else
	{
		c = '0' + n;
		write(1, &c, 1);
	}
}
