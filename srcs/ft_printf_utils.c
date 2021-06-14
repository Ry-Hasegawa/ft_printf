#include "../libftprintf.h"

void	ft_print_int(const char **format, int *i, t_flg *flg, va_list ap)
{
	int	n;
	int	len;

	(*format)++;
	n = (int)va_arg(ap, int);
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
	len = ft_actual_len(n, flg);
	if (flg->flag[1] == 1)
		ft_putnnbr(n, len);
	if (flg->width - len > 0)
		ft_put_same_char(' ', flg->width - len);
	if (flg->flag[1] == 0)
		ft_putnnbr(n, len);
	*i += ft_bigger(flg->width, len);
}

void	ft_print_char(const char **format, int *i, t_flg *flg, va_list ap)
{
	char	c;

	(*format)++;
	c = (char)va_arg(ap, int);
	if (flg->flag[1] == 1)
		ft_print_char_minus(c, flg, i);
	else
	{
		if (flg->width > 0)
		{
			*i += flg->width;
			ft_put_same_char(' ', flg->width - 1);
		}
		else
			(*i)++;
		write(1, &c, 1);
	}
}

void	ft_print_per(const char **format, int *i, t_flg *flg)
{
	(*format)++;
	(*i)++;
	if (flg->flag[1] == 1)
	{
		write(1, "%", 1);
		if (flg->width > 0)
		{
			*i += flg->width - 1;
			ft_put_same_char(' ', flg->width - 1);
		}
	}
	else
	{
		if (flg->width > 0)
		{
			*i += flg->width - 1;
			if (flg->flag[0] == 1)
				ft_put_same_char('0', flg->width - 1);
			else
				ft_put_same_char(' ', flg->width - 1);
		}
		write(1, "%", 1);
	}
}

void	ft_print_format(const char **format, int *i, t_flg *flg, va_list ap)
{
	if (**format == '%')
		ft_print_per(format, i, flg);
	else if (**format == 'c')
		ft_print_char(format, i, flg, ap);
	else if (**format == 'i' || **format == 'd')
		ft_print_int(format, i, flg, ap);
	else if (**format == 's')
		ft_print_str(format, i, flg, ap);
	else if (**format == 'p')
		ft_print_adr(format, i, flg, ap);
	else if (**format == 'u')
		ft_print_uint(format, i, flg, ap);
	else if (**format == 'x')
		ft_print_hex_low(format, i, flg, ap);
	else if (**format == 'X')
		ft_print_hex_up(format, i, flg, ap);
	else
		*i = -1;
}

void	ft_get_pre(const char **format, t_flg *flg, va_list ap)
{
	(*format)++;
	flg->pre = 0;
	if (**format == '*')
	{
		flg->pre = (int)va_arg(ap, int);
		if (flg->pre < -1)
			flg->pre = -1;
		(*format)++;
		return ;
	}
	else if (**format == '-')
	{
		flg->pre = -1;
		(*format)++;
		while (ft_isdigit(**format))
			(*format)++;
	}
	while (ft_isdigit(**format))
	{
		flg->pre *= 10;
		flg->pre += **format - '0';
		(*format)++;
	}
}
