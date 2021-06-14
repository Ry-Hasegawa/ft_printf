/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhasegaw <rhasegaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 21:02:19 by rhasegaw          #+#    #+#             */
/*   Updated: 2021/04/19 22:46:27 by rhasegaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *buf1, const void *buf2, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	int				i;

	i = 0;
	if (buf1 == buf2)
		return (buf1);
	a = (unsigned char *)buf1;
	b = (unsigned char *)buf2;
	while (n-- > 0)
	{
		a[i] = b[i];
		i++;
	}
	return (buf1);
}
