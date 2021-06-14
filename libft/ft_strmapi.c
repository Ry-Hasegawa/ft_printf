/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhasegaw <rhasegaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 17:23:50 by rhasegaw          #+#    #+#             */
/*   Updated: 2021/04/20 00:15:37 by rhasegaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int				i;
	unsigned int	j;
	char			*heap;

	if (!s || !f)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0')
		i++;
	heap = (char *)malloc(i + 1);
	if (!heap)
		return (NULL);
	while (i-- != 0)
	{
		heap[j] = f(j, s[j]);
		j++;
	}
	heap[j] = '\0';
	return (heap);
}
