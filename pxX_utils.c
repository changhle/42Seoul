/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pxX_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 22:12:55 by changhle          #+#    #+#             */
/*   Updated: 2022/03/04 22:18:20 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_xnbr_len(unsigned long long xnbr)
{
	int	len;

	len = 1;
	while (xnbr > 15)
	{
		xnbr /= 16;
		len++;
	}
	return (len);
}

void	ft_putxnbr(t_flag *flag, unsigned long long xnbr)
{
	const char	*lower_x = "0123456789abcdef";
	const char	*upper_x = "0123456789ABCDEF";

	if (xnbr > 15)
		ft_putxnbr(flag, xnbr / 16);
	if (flag->type == 'x' || flag->type == 'p')
		write(1, &lower_x[xnbr % 16], 1);
	else if (flag->type == 'X')
		write(1, &upper_x[xnbr % 16], 1);
}
