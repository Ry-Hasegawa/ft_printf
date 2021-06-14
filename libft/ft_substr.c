/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhasegaw <rhasegaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 01:14:51 by rhasegaw          #+#    #+#             */
/*   Updated: 2021/05/01 05:49:46 by rhasegaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*heap;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	if (ft_strlen(s) <= start)
		len = 0;
	heap = (char *)malloc(len + 1);
	if (!heap)
		return (NULL);
	while (len-- > 0 && s[start + i] != '\0')
	{
		heap[i] = s[start + i];
		i++;
	}
	heap[i] = '\0';
	return (heap);
}
