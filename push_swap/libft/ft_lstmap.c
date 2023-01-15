/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledos-sa <ledos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:38:49 by ledos-sa          #+#    #+#             */
/*   Updated: 2022/11/22 19:03:02 by ledos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*p;

	if (!f || !del || !lst)
		return (NULL);
	p = ft_lstnew(f(lst->content));
	if (!p)
	{
		ft_lstclear(&head, del);
		return (NULL);
	}
	lst = lst->next;
	head = p;
	while (lst)
	{
		p->next = ft_lstnew(f(lst->content));
		if (!p)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		p = p->next;
		lst = lst->next;
	}
	return (head);
}
