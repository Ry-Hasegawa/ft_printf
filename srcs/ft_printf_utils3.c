#include "../libftprintf.h"

void	ft_print_adr(const char **format, int *i, t_flg *flg, va_list ap)
{
	unsigned long long	adr;
	int					len;

	(*format)++;
	if (flg->flag[1] == 1)
	{
		ft_print_adr_minus(i, flg, ap);
		return ;
	}
	adr = (unsigned long long)va_arg(ap, void *);
	len = ft_get_adr_len(adr, flg) + 2;
	if (!adr)
	{
		len = ft_bigger(flg->pre + 2, 3);
		if (flg->pre == 0)
			len = 2;
	}
	if (flg->width - len > 0)
		ft_put_same_char(' ', flg->width - len);
	ft_putadr_pre(adr, flg);
	*i += ft_bigger(len, flg->width);
}

void	ft_fill_flg(t_flg *flg, int len)
{
	char	c;
	int		i;

	if (flg->flag[0] && !flg->flag[1])
		c = '0';
	else
		c = ' ';
	i = 0;
	while (i < flg->width - len)
	{
		write(1, &c, 1);
		i++;
	}
}

void	ft_print_str_minus(char *str, int *i, t_flg *flg)
{
	int		len;

	if (flg->pre == -1)
		len = ft_strlen(str);
	else
		len = ft_lower(flg->pre, ft_strlen(str));
	write(1, str, len);
	ft_fill_flg(flg, len);
	*i += ft_bigger(len, flg->width);
}

void	ft_print_str(const char **format, int *i, t_flg *flg, va_list ap)
{
	int		len;
	char	*str;

	(*format)++;
	str = (char *)va_arg(ap, char *);
	if (!str)
		str = "(null)";
	if (flg->flag[1] == 1)
	{
		ft_print_str_minus(str, i, flg);
		return ;
	}
	if (flg->pre == -1)
		len = ft_strlen(str);
	else
		len = ft_lower(flg->pre, ft_strlen(str));
	ft_fill_flg(flg, len);
	write(1, str, len);
	*i += ft_bigger(len, flg->width);
}

size_t	ft_power(size_t base, int n)
{
	int		i;
	size_t	ans;

	ans = base;
	i = 1;
	if (n <= 0)
		return (1);
	while (i < n)
	{
		ans *= base;
		i++;
	}
	return (ans);
}
