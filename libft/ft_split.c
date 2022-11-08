/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledos-sa <ledos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:20:16 by ledos-sa          #+#    #+#             */
/*   Updated: 2022/11/08 19:01:48 by ledos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static int	ft_count_words(const char *s, char c)
{
	int	words;
	int	i;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (i == 0 && s[i] != c)
			words++;
		if (s[i] == c && i != ft_strlen(s) - 1)
		{
			if (s[i + 1] != c)
				words++;
		}
		i++;
	}
	return (words);
}

static void	ft_alloc(const char *s, char **f, char c)
{
	int	i;
	int	size;
	int	index;

	index = 0;
	size = 0;
	i = -1;
	while (s[++i])
	{
		if (s[i] != c)
			size++;
		else
		{
			if (size)
			{
				f[index++] = malloc(sizeof(char) * (size + 1));
				size = 0;
			}
		}
	}
	if (size)
		f[index] = malloc(sizeof(char) * (size + 1));
}

static void	ft_copy(const char *s, char **f, char c, int words)
{
	int	i;
	int	j;
	int	k;

	j = 0;
	k = 0;
	i = 0;
	while (words > 0)
	{
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			f[k][j] = s[i];
			j++;
			i++;
		}
		f[k][j] = '\0';
		j = 0;
		k++;
		words--;
	}
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**p;

	if (!s)
		return (NULL);
	words = ft_count_words(s, c);
	p = malloc(sizeof(char *) * (words + 1));
	if (!p)
		return (NULL);
	ft_alloc(s, p, c);
	ft_copy(s, p, c, words);
	p[words] = 0;
	return (p);
}

/* int main(int argc, char *argv[]) */
/* { */
/*  	char *s = "                  olol"; */
/* 	char **p=ft_split(argv[1], argv[2][0]); */
/* 	for (int i=0; p[i] ; i++) */
/* 		printf("%s\n",p[i]); */
/* 	return 0; */
/* } */
	/* while (s[++i]) */
	/* { */
	/* 	if (s[i] != c) */
	/* 	{ */
	/* 		f[k][j] = s[i]; */
	/* 		j++; */
	/* 	} */
	/* 	else if (j) */
	/* 	{ */
	/* 		f[k++][j] = '\0'; */
	/* 		j = 0; */
	/* 	} */
	/* } */
