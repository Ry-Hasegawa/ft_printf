#include "../libftprintf.h"

void	ft_print_char_minus(char c, t_flg *flg, int *i)
{
	write(1, &c, 1);
	if (flg->width > 0)
	{
		*i += flg->width;
		ft_put_same_char(' ', flg->width - 1);
	}
	else
		(*i)++;
}

static void	print_str(unsigned long long long_nbr, char *base, size_t base_size)
{
	int		j;
	int		k;
	int		l;
	char	str[30];

	j = 0;
	k = 0;
	l = -1;
	while (long_nbr)
	{
		str[j] = base[long_nbr % base_size];
		long_nbr = long_nbr / base_size;
		j++;
	}
	str[j] = '\0';
	while (str[k] != '\0')
		k++;
	while (++l < k)
		write(1, &str[k - 1 - l], 1);
}

void	ft_putnbr_base(unsigned long long nbr, char *base)
{
	size_t				i;
	unsigned long long	long_nbr;

	i = ft_strlen(base);
	long_nbr = nbr;
	if (long_nbr == 0)
		write(1, &base[0], 1);
	else
		print_str(long_nbr, base, i);
}
