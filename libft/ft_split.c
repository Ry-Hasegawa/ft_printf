/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhasegaw <rhasegaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 19:12:26 by rhasegaw          #+#    #+#             */
/*   Updated: 2021/04/20 00:15:50 by rhasegaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	sep_check(char x, char c)
{
	if (x == '\0')
		return (0);
	else if (c == x)
		return (0);
	else
		return (1);
}

static void	ft_strncpy(char *dest, char const *src, unsigned int n)
{
	unsigned int	index;

	index = 0;
	while (index < n)
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
}

static char	**put_array(char const *str, char **heap, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (str[i] != '\0')
	{
		j = 0;
		if (sep_check(str[i], c) == 0)
			i++;
		else
		{
			while (sep_check(str[i + j], c) == 1)
				j++;
			heap[k] = (char *)malloc(sizeof(char) * (j + 1));
			if (!heap[k])
				return (NULL);
			ft_strncpy(heap[k], &str[i], j);
			i += j;
			k++;
		}
	}
	return (heap);
}

static int	array_size(char const *str, char c)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (str[i] != '\0')
	{
		if (sep_check(str[i], c) == 1)
		{
			if (sep_check(str[i + 1], c) == 0)
				k++;
		}
		i++;
	}
	return (k);
}

char	**ft_split(char const *s, char c)
{
	int		size;
	char	**p;
	char	**result;
	int		i;

	if (!s)
		return (NULL);
	size = array_size(s, c);
	p = (char **)malloc(sizeof(char *) * (size + 1));
	if (!p)
		return (NULL);
	result = put_array(s, p, c);
	i = 0;
	if (result == 0)
	{
		while (p[i] != 0)
		{
			free(p[i]);
			i++;
		}
		free(p);
		return (NULL);
	}
	result[size] = 0;
	return (result);
}
