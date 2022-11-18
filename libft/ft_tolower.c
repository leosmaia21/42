/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 16:38:24 by ledos-sa          #+#    #+#             */
/*   Updated: 2022/11/06 16:38:27 by ledos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c < -1)
		return ((unsigned char)c);
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

/*#include <ctype.h>
int	main(void)
{
		int	c = 'R';
	printf("%d \n", ft_tolower(c));
	printf("%d", tolower(c));
	return (0);
}*/
