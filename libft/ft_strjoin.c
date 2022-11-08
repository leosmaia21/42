/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:29:50 by ledos-sa          #+#    #+#             */
/*   Updated: 2022/11/08 19:00:35 by ledos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

/* int main(int argc, char *argv[]) */
/* { */
/* 	char s1[]="ola"; */
/* 	char s2[]="ole"; */
/* 	printf("%s",ft_strjoin(s1,s2)); */
/* 	return 0; */
/* } */
