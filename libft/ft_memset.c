/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhasegaw <rhasegaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 21:39:58 by rhasegaw          #+#    #+#             */
/*   Updated: 2021/04/19 22:46:12 by rhasegaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buf, int ch, size_t n)
{
	unsigned char	a;
	unsigned char	*p;
	int				i;

	i = 0;
	a = ch;
	p = (unsigned char *)buf;
	while (n-- > 0)
	{
		p[i] = a;
		i++;
	}
	return (buf);
}
