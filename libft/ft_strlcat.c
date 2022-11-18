/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 14:56:38 by ledos-sa          #+#    #+#             */
/*   Updated: 2022/11/07 23:28:29 by ledos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

unsigned int	ft_strlcat(char *dst, char *src, size_t size)
{
	size_t	srclen;
	size_t	dstlen;
	size_t	i;

	i = 0;
	srclen = ft_strlen(src);
	if (!size)
		return (srclen);
	dstlen = ft_strlen(dst);
	if (dstlen >= size)
		return (size + srclen);
	if (dstlen < size -1 && size > 0)
	{
		while (src[i] && i < size - 1 - dstlen)
		{
			dst[dstlen + i] = src[i];
			i++;
		}
		dst[dstlen + i] = '\0';
	}
	return (dstlen + srclen);
}
