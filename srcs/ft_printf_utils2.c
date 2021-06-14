#include "../libftprintf.h"

void	ft_putnnbr(int n, int len)
{
	int		n_len;
	size_t	div;
	long	nb;
	char	c;

	n_len = ft_count_digits(n);
	div = ft_power(10, n_len - 1);
	nb = (long)n;
	if (n < 0)
		div /= 10;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	if (len - n_len > 0)
		ft_put_same_char('0', len - n_len);
	while (div > 0)
	{
		c = nb / div + '0';
		write(1, &c, 1);
		nb %= div;
		div /= 10;
	}
}

int	ft_count_digits(long n)
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

int	ft_actual_len(int n, t_flg *flg)
{
	int	i;

	i = 0;
	if (flg->pre == -1)
	{
		if (flg->flag[0] == 1)
			i = ft_bigger(flg->width, ft_count_digits(n));
		else
			i = ft_count_digits(n);
	}
	else if (flg->pre == 0)
		i = ft_count_digits(n);
	else
	{
		if (n < 0)
			i = ft_bigger(flg->pre + 1, ft_count_digits(n));
		else
			i = ft_bigger(flg->pre, ft_count_digits(n));
	}
	return (i);
}

void	ft_print_zero_minus(int *i, t_flg *flg)
{
	if (flg->pre == -1)
	{
		if (flg->flag[0] == 1 && flg->width > 0)
			ft_put_same_char('0', flg->width - 1);
		write(1, "0", 1);
		if (flg->flag[0] == 0 && flg->width > 0)
			ft_put_same_char(' ', flg->width - 1);
	}
	if (flg->pre == 0 && flg->width > 0)
		ft_put_same_char(' ', flg->width);
	if (flg->pre > 0)
	{
		ft_put_same_char('0', flg->pre);
		if (flg->width > flg->pre)
			ft_put_same_char(' ', flg->width - flg->pre);
	}
	if (flg->pre > 0 || flg->width > 0)
		*i += ft_bigger(flg->pre, flg->width);
	else if (flg->pre != 0)
		*i += 1;
}

void	ft_print_zero(int *i, t_flg *flg)
{
	if (flg->pre == -1)
	{
		if (flg->flag[0] == 1 && flg->width > 0)
			ft_put_same_char('0', flg->width - 1);
		if (flg->flag[0] == 0 && flg->width > 0)
			ft_put_same_char(' ', flg->width - 1);
		write(1, "0", 1);
	}
	if (flg->pre == 0 && flg->width > 0)
		ft_put_same_char(' ', flg->width);
	if (flg->pre > 0)
	{
		if (flg->width > flg->pre)
			ft_put_same_char(' ', flg->width - flg->pre);
		ft_put_same_char('0', flg->pre);
	}
	if (flg->pre > 0 || flg->width > 0)
		*i += ft_bigger(flg->pre, flg->width);
	else if (flg->pre != 0)
		*i += 1;
}
