#include "../libftprintf.h"

int	ft_count_digits_u(unsigned int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

void	ft_puthex_pre(unsigned int num, int up_sign, int len)
{
	size_t	div;
	int		digits;
	char	*base;

	digits = ft_count_digits_sixt((unsigned long long)num);
	div = ft_power(16, digits - 1);
	if (len - digits > 0)
		ft_put_same_char('0', len - digits);
	if (up_sign)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	while (div > 0)
	{
		write(1, &base[num / div], 1);
		num %= div;
		div /= 16;
	}
}

int	ft_actual_hex_len(unsigned int num, t_flg *flg)
{
	int	i;

	if (flg->pre == -1)
	{
		if (flg->flag[0] == 1)
			i = ft_bigger(flg->width,
					ft_count_digits_sixt((unsigned long long)num));
		else
			i = ft_count_digits_sixt((unsigned long long)num);
	}
	else if (flg->pre == 0)
		i = ft_count_digits_sixt((unsigned long long)num);
	else
	{
		if (num < 0)
			i = ft_bigger(flg->pre + 1,
					ft_count_digits_sixt((unsigned long long)num));
		else
			i = ft_bigger(flg->pre,
					ft_count_digits_sixt((unsigned long long)num));
	}
	return (i);
}

void	ft_print_hex_up(const char **format, int *i, t_flg *flg, va_list ap)
{
	unsigned int	num;
	int				len;

	(*format)++;
	num = va_arg(ap, unsigned int);
	if (num == 0 && flg->flag[1] == 1)
	{
		ft_print_zero_minus(i, flg);
		return ;
	}
	else if (num == 0 && flg->flag[1] == 0)
	{
		ft_print_zero(i, flg);
		return ;
	}
	len = ft_actual_hex_len(num, flg);
	if (flg->flag[1] == 1)
		ft_puthex_pre(num, 1, len);
	if (flg->width - len > 0)
		ft_put_same_char(' ', flg->width - len);
	if (flg->flag[1] == 0)
		ft_puthex_pre(num, 1, len);
	*i += ft_bigger(len, flg->width);
}

void	ft_print_hex_low(const char **format, int *i, t_flg *flg, va_list ap)
{
	unsigned int	num;
	int				len;

	(*format)++;
	num = va_arg(ap, unsigned int);
	if (num == 0 && flg->flag[1] == 1)
	{
		ft_print_zero_minus(i, flg);
		return ;
	}
	else if (num == 0 && flg->flag[1] == 0)
	{
		ft_print_zero(i, flg);
		return ;
	}
	len = ft_actual_hex_len(num, flg);
	if (flg->flag[1] == 1)
		ft_puthex_pre(num, 0, len);
	if (flg->width - len > 0)
		ft_put_same_char(' ', flg->width - len);
	if (flg->flag[1] == 0)
		ft_puthex_pre(num, 0, len);
	*i += ft_bigger(len, flg->width);
}
