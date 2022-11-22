/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 22:19:53 by ledos-sa          #+#    #+#             */
/*   Updated: 2022/11/10 16:58:35 by ledos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	size_t		c;
	char		*p;

	if (!s)
		return (NULL);
	c = ft_strlen(s);
	if (start > c)
		start = c;
	if ((start + len) > c)
		len = c - start;
	p = malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	i = 0;
	while (i < len)
	{
		p[i] = s[i + start];
		i++;
	}
	p[i] = '\0';
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
