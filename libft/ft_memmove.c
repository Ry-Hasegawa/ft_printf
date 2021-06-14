/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhasegaw <rhasegaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 21:03:04 by rhasegaw          #+#    #+#             */
/*   Updated: 2021/04/19 22:50:47 by rhasegaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *buf1, const void *buf2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;
	size_t			i;

	i = 0;
	p1 = (unsigned char *)buf1;
	p2 = (unsigned char *)buf2;
	if (p1 == p2)
		return (buf1);
	if (p1 < p2)
	{
		while (n-- > 0)
		{
			p1[i] = p2[i];
			i++;
		}
	}
	else
	{
		i = n;
		while (i-- > 0)
			p1[i] = p2[i];
	}
	return (buf1);
}
