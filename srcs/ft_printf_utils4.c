#include "../libftprintf.h"

void	ft_print_uint(const char **format, int *i, t_flg *flg, va_list ap)
{
	unsigned int	n;
	int				len;

	(*format)++;
	n = (unsigned int)va_arg(ap, unsigned int);
	if (n == 0 && flg->flag[1] == 1)
	{
		ft_print_zero_minus(i, flg);
		return ;
	}
	else if (n == 0 && flg->flag[1] == 0)
	{
		ft_print_zero(i, flg);
		return ;
	}
	len = ft_actual_ulen(n, flg);
	if (flg->flag[1] == 1)
		ft_putnnbr_u(n, len);
	if (flg->width - len > 0)
		ft_put_same_char(' ', flg->width - len);
	if (flg->flag[1] == 0)
		ft_putnnbr_u(n, len);
	*i += ft_bigger(flg->width, len);
}

int	ft_count_digits_sixt(unsigned long long n)
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
		n /= 16;
		i++;
	}
	return (i);
}

void	ft_putadr_pre(unsigned long long adr, t_flg *flg)
{
	int	i;

	i = 0;
	write(1, "0x", 2);
	if (adr != 0)
	{
		while (i++ < flg->pre - 9)
			write(1, "0", 1);
		ft_putnbr_base(adr, "0123456789abcdef");
	}
	else
	{
		while (i < flg->pre - 1)
		{
			write(1, "0", 1);
			i++;
		}
		if (flg->pre != 0)
			write(1, "0", 1);
	}
}

int	ft_get_adr_len(unsigned long long ptr, t_flg *flg)
{
	int	i;

	if (flg->pre == -1)
	{
		if (flg->flag[0] == 1)
			i = ft_bigger(flg->width, ft_count_digits_sixt(ptr));
		else
			i = ft_count_digits_sixt(ptr);
	}
	else if (flg->pre == 0)
		i = ft_count_digits_sixt(ptr);
	else
	{
		if (ptr < 0)
			i = ft_bigger(flg->pre + 1, ft_count_digits_sixt(ptr));
		else
			i = ft_bigger(flg->pre, ft_count_digits_sixt(ptr));
	}
	return (i);
}

void	ft_print_adr_minus(int *i, t_flg *flg, va_list ap)
{
	unsigned long long	adr;
	int					len;
	int					j;

	adr = (unsigned long long)va_arg(ap, void *);
	len = ft_get_adr_len(adr, flg) + 2;
	if (!adr)
	{
		if (flg->pre == 0)
			len = 2;
		else
			len = ft_bigger(flg->pre + 2, 3);
	}
	j = 0;
	ft_putadr_pre(adr, flg);
	while (j < flg->width - len)
	{
		write(1, " ", 1);
		j++;
	}
	*i += ft_bigger(len, flg->width);
}
