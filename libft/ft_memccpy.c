/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhasegaw <rhasegaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 21:39:19 by rhasegaw          #+#    #+#             */
/*   Updated: 2021/04/19 22:46:48 by rhasegaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *buf1, const void *buf2, int c, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	unsigned char	k;
	int				i;

	i = 0;
	if (buf1 == buf2)
		return (buf1);
	a = (unsigned char *)buf1;
	b = (unsigned char *)buf2;
	k = c;
	while (n-- > 0)
	{
		if (b[i] == k)
		{
			a[i] = b[i];
			i++;
			return (&a[i]);
		}
		a[i] = b[i];
		i++;
	}
	return (0);
}
