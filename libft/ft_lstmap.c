/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhasegaw <rhasegaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 18:43:07 by rhasegaw          #+#    #+#             */
/*   Updated: 2021/04/20 00:20:31 by rhasegaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*p;
	t_list	*new;

	p = 0;
	while (lst)
	{
		new = ft_lstnew(f(lst->content));
		if (new == 0)
		{
			ft_lstclear(&p, del);
			return (NULL);
		}
		ft_lstadd_back(&p, new);
		lst = lst->next;
	}
	return (p);
}
