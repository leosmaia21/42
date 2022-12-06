/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 13:44:28 by ledos-sa          #+#    #+#             */
/*   Updated: 2022/11/10 16:25:19 by ledos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*pdest;
	char	*psrc;

	if (n == 0 || dest == src)
		return (dest);
	pdest = (char *)dest;
	psrc = (char *)src;
	while (n)
	{
		*(pdest++) = *(psrc++);
		--n;
	}
	return (dest);
}
