/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 16:38:34 by ledos-sa          #+#    #+#             */
/*   Updated: 2022/11/06 16:38:44 by ledos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c < -1)
		return ((unsigned char)c);
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

/*#include <ctype.h>
int	main(void)
{
	int	c = -4905;
	printf("%d \n", ft_toupper(c));
	printf("%d", toupper(c));
	return (0);
}*/
