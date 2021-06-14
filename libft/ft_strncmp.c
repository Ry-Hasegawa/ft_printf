/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhasegaw <rhasegaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 02:53:18 by rhasegaw          #+#    #+#             */
/*   Updated: 2021/04/19 23:25:54 by rhasegaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	size_t			i;
	int				diff;

	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	i = 0;
	while ((!(a[i] == '\0' && b[i] == '\0')) && i < n)
	{
		if (a[i] != b[i])
		{
			diff = a[i] - b[i];
			return (diff);
		}
		else
			i++;
	}
	return (0);
}
