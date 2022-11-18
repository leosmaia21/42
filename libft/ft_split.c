/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledos-sa <ledos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:20:16 by ledos-sa          #+#    #+#             */
/*   Updated: 2022/11/08 20:05:58 by ledos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_n_words(char const *s, char c)
{
	size_t		i;
	size_t		n;

	i = 0;
	n = 0;
	while (s[i])
	{
		if (s[i] != c && i == 0)
			n++;
		else if (s[i] == c && i != (size_t)ft_strlen(s) - 1)
		{
			if (s[i + 1] != c)
				n++;
		}
		i++;
	}
	return (n);
}

static void	ft_str_word_create(const char *s, char **str, char c)
{
	size_t	i;
	size_t	len;
	size_t	j;

	i = 0;
	len = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
			len++;
		else
		{
			if (len != 0)
			{
				str[j] = (char *)malloc(sizeof(char) * len + 1);
				len = 0;
				j++;
			}
		}
		if (len != 0)
			str[j] = (char *)malloc(sizeof(char) * len + 1);
		i++;
	}
}

static void	ft_str_word_fill(const char *s, char **str, char c, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	while (n > 0 && s[i])
	{
		while (s[i] == c)
			i++;
		while (s[i] != c)
		{
			str[j][k] = s[i];
			i++;
			k++;
		}
		str[j][k] = '\0';
		k = 0;
		j++;
		n--;
	}
}

char	**ft_split(char const *s, char c)
{
	size_t	n;
	char	**str;

	if (!s)
		return (0);
	n = ft_n_words(s, c);
	str = (char **)malloc(n * sizeof(char *) + 1);
	if (str == NULL)
		return (NULL);
	ft_str_word_create(s, str, c);
	ft_str_word_fill(s, str, c, n);
	str[n] = 0;
	return (str);
}
