/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 22:12:14 by changhle          #+#    #+#             */
/*   Updated: 2022/03/04 22:12:14 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_flag(t_flag *flag)
{
	flag->f_minus = -1;
	flag->f_plus = -1;
	flag->f_zero = -1;
	flag->f_hash = -1;
	flag->f_space = -1;
	flag->width = 0;
	flag->dot = 0;
	flag->precision = 0;
	flag->type = 0;
}

void	set_flag(const char *format, int index, t_flag *flag)
{
	if (format[index] == '-')
		flag->f_minus = index;
	else if (format[index] == '0')
		flag->f_zero = index;
	else if (format[index] == '#')
		flag->f_hash = index;
	else if (format[index] == '+')
		flag->f_plus = index;
	else if (format[index] == ' ')
		flag->f_space = index;
}

int	print(t_flag *flag, va_list ap)
{
	int	ret;

	ret = 0;
	if (flag->type == 'c')
		ret = type_c(flag, ap);
	else if (flag->type == 's')
		ret = type_s(flag, ap);
	else if (flag->type == 'd' || flag->type == 'i' || flag->type == 'u')
		ret = type_diu(flag, ap);
	else if (flag->type == 'x' || flag->type == 'X' || flag->type == 'p')
		ret = type_px(flag, ap);
	else if (flag->type == '%')
		ret = type_percent(flag);
	return (ret);
}

int	parse(const char *format, int *index, t_flag *flag, va_list ap)
{
	int	ret;

	(*index)++;
	init_flag(flag);
	while (ft_strchr("-0#+ ", format[*index]))
		set_flag(format, (*index)++, flag);
	while (ft_strchr("0123456789", format[*index]))
		flag->width = flag->width * 10 + (format[(*index)++] - '0');
	if (format[*index] == '.')
	{
		flag->dot = 1;
		(*index)++;
		while (ft_strchr("0123456789", format[*index]))
			flag->precision = flag->precision * 10 + (format[(*index)++] - '0');
	}
	if (ft_strchr("cspdiuxX%", format[*index]))
		flag->type = format[*index];
	ret = print(flag, ap);
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	int		index;
	int		ret;
	va_list	ap;
	t_flag	flag;

	va_start(ap, format);
	index = 0;
	ret = 0;
	while (format[index])
	{
		if (format[index] == '%')
			ret += parse(format, &index, &flag, ap);
		else
		{
			write(1, &format[index], 1);
			ret++;
		}
		index++;
	}
	va_end(ap);
	return (ret);
}
