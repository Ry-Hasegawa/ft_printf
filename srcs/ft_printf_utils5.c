#include "../libftprintf.h"

void	ft_put_same_char(char c, int n)
{
	while (n)
	{
		write(1, &c, 1);
		n--;
	}	
}

int	ft_bigger(int a, int b)
{
	if (a < b)
		return (b);
	else
		return (a);
}

int	ft_lower(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

void	ft_putnnbr_u(unsigned int n, int len)
{
	int		n_len;
	size_t	div;
	long	nb;
	char	c;

	n_len = ft_count_digits_u(n);
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

int	ft_actual_ulen(unsigned int n, t_flg *flg)
{
	int	i;

	i = 0;
	if (flg->pre == -1)
	{
		if (flg->flag[0] == 1)
			i = ft_bigger(flg->width, ft_count_digits_u(n));
		else
			i = ft_count_digits_u(n);
	}
	else if (flg->pre == 0)
		i = ft_count_digits_u(n);
	else
	{
		if (n < 0)
			i = ft_bigger(flg->pre + 1, ft_count_digits_u(n));
		else
			i = ft_bigger(flg->pre, ft_count_digits_u(n));
	}
	return (i);
}
