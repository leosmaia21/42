/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 13:31:52 by ledos-sa          #+#    #+#             */
/*   Updated: 2022/11/06 13:42:07 by ledos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memset(void *s, int c, int n)
{
	unsigned char	*p;
	int				i;

	i = 0;
	p = (unsigned char *)s;
	while (i < n)
	{
		p[i] = (char)c;
		i++;
	}
	return (p);
}
