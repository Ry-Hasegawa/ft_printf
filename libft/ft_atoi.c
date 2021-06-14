/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhasegaw <rhasegaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 02:54:29 by rhasegaw          #+#    #+#             */
/*   Updated: 2021/04/20 19:07:41 by rhasegaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long	ft_check(unsigned long ans, int digit)
{
	if (ans <= (unsigned long)((LONG_MAX - digit) / 10))
		return (ans);
	else
		return (0);
}

static long	ft_output(int sign)
{
	if (sign == -1)
		return (LONG_MIN);
	else
		return (LONG_MAX);
}

static long	ft_convert_to_int(const char *str, long i, int j)
{
	unsigned long	k;

	k = 0;
	while ('0' == str[i])
	{
		k = k * 10 + (str[i] - '0');
		i++;
	}
	if ('0' <= str[i] && str[i] <= '9')
	{
		k = k * 10 + (str[i] - '0');
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		k = ft_check(k, str[i] - '0');
		if (k == 0)
			return (ft_output(j));
		k = k * 10 + (str[i] - '0');
		i++;
	}
	return (k * j);
}

int	ft_atoi(const char *str)
{
	long			i;
	int				j;

	i = 0;
	j = 1;
	while ((str[i] >= '\t' && str[i] <= '\r' ) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			j *= (-1);
		i++;
	}
	return (ft_convert_to_int(str, i, j));
}
