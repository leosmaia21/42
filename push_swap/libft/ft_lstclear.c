/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledos-sa <ledos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:24:40 by ledos-sa          #+#    #+#             */
/*   Updated: 2022/11/08 17:32:39 by ledos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*n;

	if (!del || !lst || !(*lst))
		return ;
	while (*lst && lst)
	{
		n = (*lst)->next;
		del((*lst)->content);
		free((*lst));
		*lst = n;
	}
}
