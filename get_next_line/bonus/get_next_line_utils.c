/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledos-sa <ledos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 20:46:50 by ledos-sa          #+#    #+#             */
/*   Updated: 2022/11/18 22:42:02 by ledos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t		i;
	char		*p;

	p = malloc(nmemb * size);
	if (!p)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		p[i] = 0;
		i++;
	}
	return (p);
}

int	ft_strlen(const char *s)
{
	int	x;

	x = 0;
	while (s[x] != '\0')
		x++;
	return (x);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1l;
	int		s2l;
	int		alllen;
	char	*final;
	int		c;

	if (!s1 || !s2)
		return (NULL);
	c = 0;
	s1l = ft_strlen(s1);
	s2l = ft_strlen(s2);
	alllen = s1l + s2l;
	final = malloc(sizeof(char) * (alllen + 1));
	if (!final)
		return (NULL);
	while (c < alllen)
	{
		if (c < s1l)
			final[c] = s1[c];
		else
			final[c] = s2[c - s1l];
		c++;
	}
	final[c] = 0;
	return (final);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (&str[i]);
		i++;
	}
	if (c == '\0')
		return (&str[i]);
	return (0);
}

unsigned	int	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	length;

	length = ft_strlen(src);
	i = 0;
	if (size > 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (length);
}
