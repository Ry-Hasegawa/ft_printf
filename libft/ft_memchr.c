/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhasegaw <rhasegaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 21:39:40 by rhasegaw          #+#    #+#             */
/*   Updated: 2021/04/19 22:49:30 by rhasegaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *buf, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	k;

	p = (unsigned char *)buf;
	k = c;
	while (n-- > 0)
	{
		if (*p == k)
			return (p);
		p++;
	}
	return (0);
}
