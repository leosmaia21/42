/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:30:41 by ledos-sa          #+#    #+#             */
/*   Updated: 2022/11/10 16:37:53 by ledos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*str;
	size_t	i;
	size_t	n;

	n = nmemb * size;
	str = (char *)malloc(n);
	if (str == NULL)
		return (0);
	i = 0;
	while (n > 0)
	{
		str[i] = 0;
		i++;
		n--;
	}
	return ((void *)str);
}
