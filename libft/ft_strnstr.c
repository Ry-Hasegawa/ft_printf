/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhasegaw <rhasegaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 20:55:22 by rhasegaw          #+#    #+#             */
/*   Updated: 2021/04/19 23:17:26 by rhasegaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	j;
	int		k;
	int		l;

	j = ft_strlen(to_find);
	k = 0;
	l = 0;
	if (to_find[l] == '\0')
		return ((char *)str);
	while (str[k] != '\0' && n >= j)
	{
		n--;
		while (str[k + l] == to_find[l])
		{
			l++;
			if (to_find[l] == '\0')
				return ((char *)&str[k]);
		}
		l = 0;
		k++;
	}
	return (NULL);
}
