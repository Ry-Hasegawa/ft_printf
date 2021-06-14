/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhasegaw <rhasegaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 22:49:01 by rhasegaw          #+#    #+#             */
/*   Updated: 2021/04/20 19:41:06 by rhasegaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digit(long n)
{
	int		i;
	long	nb;

	i = 0;
	nb = n;
	if (nb < 0)
	{
		i++;
		nb *= (-1);
	}
	while (nb)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

static char	*zero_itoa(void)
{
	char	*heap;

	heap = (char *)malloc(2);
	if (!heap)
		return (NULL);
	heap[0] = '0';
	heap[1] = '\0';
	return (heap);
}

char	*ft_itoa(int n)
{
	char	*heap;
	long	nb;
	int		len;

	nb = n;
	if (nb == 0)
		return (zero_itoa());
	len = count_digit(nb);
	heap = (char *)malloc(len + 1);
	if (!heap)
		return (NULL);
	if (nb < 0)
	{
		nb *= (-1);
		heap[0] = '-';
	}
	heap[len] = '\0';
	while (nb != 0 && heap[len - 1] != '-')
	{
		heap[len - 1] = '0' + nb % 10;
		nb /= 10;
		len--;
	}
	return (heap);
}
