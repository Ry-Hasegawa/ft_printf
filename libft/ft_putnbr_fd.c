/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhasegaw <rhasegaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 00:57:23 by rhasegaw          #+#    #+#             */
/*   Updated: 2021/04/22 12:53:17 by rhasegaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		i = -1;
		write(fd, "-", 1);
	}
	if (n < 10 && n > -10)
		ft_putchar('0' + n * i, fd);
	if (n <= -10 || 10 <= n)
	{
		ft_putnbr_fd(n / 10 * i, fd);
		ft_putchar('0' + n % 10 * i, fd);
	}
}
