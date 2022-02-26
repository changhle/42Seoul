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
	const char	*x = "0123456789abcdef";
	const char	*X = "0123456789ABCDEF";

	if (xnbr > 15)
		ft_putxnbr(flag, xnbr / 16);
	if (flag->type == 'x' || flag->type == 'p')
		write(1, &x[xnbr % 16], 1);
	else if (flag->type == 'X')
		write(1, &X[xnbr % 16], 1);
}
