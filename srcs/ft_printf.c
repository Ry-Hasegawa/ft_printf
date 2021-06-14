#include "../libftprintf.h"

void	ft_get_width(const char **format, t_flg *flg, va_list ap)
{
	int	i;

	i = 0;
	if (**format == '*')
	{
		flg->width = (int)va_arg(ap, int);
		if (flg->width < 0)
		{
			flg->width *= -1;
			flg->flag[1] = 1;
			flg->flag[0] = 0;
		}
		(*format)++;
		return ;
	}
	while (ft_isdigit(**format))
	{
		i *= 10;
		i += **format - '0';
		(*format)++;
	}
	flg->width = i;
}

void	ft_flg_init(t_flg *flg)
{
	flg->flag[0] = 0;
	flg->flag[1] = 0;
	flg->width = -1;
	flg->pre = -1;
}

void	ft_format_processing(const char **format, int *i, va_list ap)
{
	t_flg	flg;

	(*format)++;
	ft_flg_init(&flg);
	while (**format == '0' || **format == '-')
	{
		if (**format == '0')
			flg.flag[0] = 1;
		if (**format == '-')
			flg.flag[1] = 1;
		(*format)++;
	}
	ft_get_width(format, &flg, ap);
	if (flg.width == INT_MIN || flg.width == INT_MAX)
		*i = -1;
	if (**format == '.')
		ft_get_pre(format, &flg, ap);
	ft_print_format(format, i, &flg, ap);
}

void	ft_write_str(const char *start, const char **format, int *i)
{
	while (**format != '%' && **format)
		(*format)++;
	write(1, start, (size_t)*format - (size_t)start);
	*i += (int)(*format - start);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			i;
	const char	*start;

	i = 0;
	va_start(ap, format);
	if (!format)
		i = -1;
	while (i >= 0 && *format)
	{
		start = format;
		if (*start != '%')
			ft_write_str(start, &format, &i);
		else
			ft_format_processing(&format, &i, ap);
	}
	va_end(ap);
	return (i);
}
