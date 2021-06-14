/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhasegaw <rhasegaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 21:44:57 by rhasegaw          #+#    #+#             */
/*   Updated: 2021/04/20 00:16:44 by rhasegaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcat(char *dest, char *src)
{
	int		k;
	int		l;

	k = 0;
	while (dest[k] != '\0')
		k++;
	l = 0;
	while (src[l] != '\0')
	{
		dest[k] = src[l];
		k++;
		l++;
	}
	dest[k] = '\0';
	return (dest);
}

static int	total_len(char const *s1, char const *s2)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
		j++;
	return (i + j);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*heap;
	int		k;

	if (!s1 || !s2)
		return (NULL);
	k = total_len(s1, s2);
	heap = (char *)malloc(k + 1);
	if (!heap)
		return (NULL);
	*heap = 0;
	ft_strcat(heap, (char *)s1);
	ft_strcat(heap, (char *)s2);
	return (heap);
}
