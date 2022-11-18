/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 13:44:28 by ledos-sa          #+#    #+#             */
/*   Updated: 2022/11/07 22:20:05 by ledos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*pdest;
	char	*psrc;

	pdest = (char *)dest;
	psrc = (char *)src;
	if ((pdest != NULL) && (psrc != NULL))
	{
		while (n)
		{
			*(pdest++) = *(psrc++);
			--n;
		}
	}
	return (dest);
}
