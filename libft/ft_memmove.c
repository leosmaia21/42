/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 13:57:04 by ledos-sa          #+#    #+#             */
/*   Updated: 2022/11/06 20:01:02 by ledos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*pdest;
	char		*psrc;
	char		*tmp;
	size_t		i;

	pdest = (char *)dest;
	psrc = (char *)src;
	i = -1;
	tmp = (char *)malloc(sizeof(char ) * n);
	if (NULL == tmp)
		return (NULL);
	else
	{
		while (++i < n)
			tmp[i] = psrc[i];
		i = -1;
		while (++i < n)
			pdest[i] = tmp[i];
	}
	free(tmp);
	return (dest);
}
