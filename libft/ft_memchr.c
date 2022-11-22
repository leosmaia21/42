/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 16:35:20 by ledos-sa          #+#    #+#             */
/*   Updated: 2022/11/06 17:04:21 by ledos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	c2;
	int				i;

	i = 0;
	str = (unsigned char *)s;
	c2 = (unsigned char)c;
	while (n > 0)
	{
		if (str[i] == c2)
			return ((void *)&str[i]);
		n--;
		i++;
	}
	return (0);
}

/*#include <stdio.h>
int	main(void)
{
	char	str[] = "tetcectecste";
	int		n = 4;
	int		c = 'c';

	printf("%s \n", (char *)memchr(str, c, n));
	printf("%s", (char *)ft_memchr(str, c, n));
	return (0);
}*/
