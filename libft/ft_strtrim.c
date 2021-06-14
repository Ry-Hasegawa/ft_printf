/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhasegaw <rhasegaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 17:38:28 by rhasegaw          #+#    #+#             */
/*   Updated: 2021/04/22 12:21:22 by rhasegaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	set_check(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	len_check(char const *s1, char const *set)
{
	size_t	len;
	size_t	i;
	int		j;

	len = ft_strlen(s1);
	i = ft_strlen(s1);
	j = 0;
	while (set_check(s1[j], set) == 1)
	{
		len--;
		j++;
	}
	if (s1[j] == '\0')
		return (len);
	while (set_check(s1[i - 1], set) == 1)
	{
		len--;
		i--;
	}
	return ((int)len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len;
	int		i;
	int		j;
	int		k;
	char	*heap;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	j = 0;
	len = len_check(s1, set);
	heap = (char *)malloc(len + 1);
	if (!heap)
		return (NULL);
	while (set_check(s1[i], set) == 1)
		i++;
	k = len + i;
	while (i < k)
	{
		heap[j] = s1[i];
		j++;
		i++;
	}
	heap[j] = '\0';
	return (heap);
}
