/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:04:43 by ledos-sa          #+#    #+#             */
/*   Updated: 2022/11/10 17:04:48 by ledos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (*(s++) == 0)
			return (NULL);
	}
	return ((char *)s);
}

/*int	main(void)
{
	char	str[] = "testectescte";
	int		c = 'c';

	printf("%s", ft_strchr(str, c));
	printf("\n%s", strchr(str, c));
	return (0);
}*/
