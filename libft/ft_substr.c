/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 22:19:53 by ledos-sa          #+#    #+#             */
/*   Updated: 2022/11/08 03:15:32 by ledos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	size_t		c;
	char		*p;

	p = malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	if ((unsigned int)ft_strlen(s) <= start)
	{
		p[0] = 0;
		return (p);
	}
	i = start;
	c = 0;
	while (s[i])
	{
		if (i >= start && c < len)
		{
			p[c] = s[i];
			c++;
		}
		i++;
	}
	p[c] = 0;
	return (p);
}

/* int	main(void) */
/* { */
/* 	char	str[] = "abcdef"; */
/* 	char	to_find[] = "x"; */

/* 	printf("ft_strcat(str) = %s\n", ft_strstr(str, to_find)); */
/* 	printf("ft_strcat(str) = %s\n", strstr(str, to_find)); */
/* 	return (0); */
/* } */
