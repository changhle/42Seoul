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
		ret = print_c(flag, ap);
	else if (flag->type == 's')
		ret = print_s(flag, ap);
	else if (flag->type == 'd' || flag->type == 'i')
		ret = print_di(flag, ap);
	else if (flag->type == 'u')
		ret = print_u(flag, ap);
	else if (flag->type == 'x' || flag->type == 'X' || flag->type == 'p')
		ret = print_pxX(flag, ap);
	else if (flag->type == '%')
		ret = print_percent(flag);
	return (ret);
}

int	parse(const char *format, int *index, t_flag *flag, va_list ap)
{
	(*index)++;
	init_flag(flag);
	while (ft_strchr("-0#+ ", format[*index]))
		set_flag(format, (*index)++, flag);
	while (ft_strchr("0123456789", format[*index]))
		flag->width = flag->width * 10 + format[(*index)++] - '0';
	if (format[*index] == '.')
	{
		flag->dot = 1;
		(*index)++;
		while (ft_strchr("0123456789", format[*index]))
			flag->precision = flag->precision * 10 + format[(*index)++] - '0';
	}
	if (ft_strchr("cspdiuxX%", format[*index]))
		flag->type = format[*index];
	return (print(flag, ap));
}

int	ft_printf(const char *format, ...)
{
	int		index;
	int		ret;
	va_list	ap;
	t_flag	*flag;

	va_start(ap, format);
	index = 0;
	ret = 0;
	flag = malloc(sizeof(t_flag));
	while (format[index])
	{
		if (format[index] == '%')
			ret += parse(format, &index, flag, ap);
		else
		{
			write(1, &format[index], 1);
			ret++;
		}
		index++;
	}
	va_end(ap);
	free(flag);
	return (ret);
}
