/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 16:35:00 by ledos-sa          #+#    #+#             */
/*   Updated: 2022/11/07 23:33:39 by ledos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	c;
	int	res;
	int	n;

	i = 0;
	c = 1;
	res = 0;
	n = 0;
	while (nptr[i] == '\t' || nptr[i] == '\n' || nptr[i] == '\v' || \
		nptr[i] == '\f' || nptr[i] == '\r' || nptr[i] == ' ')
		i++;
	while ((nptr[i] == '+' || nptr[i] == '-') && c == 1 && n == 0)
	{
		if (nptr[i] == '-')
			c = -1;
		i++;
		n++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	return (res * c);
}

/*int	main(void)
{
	char 	nptr[] = "     +2734hdn984";
	printf("%d \n", atoi(nptr));
	printf("%d", ft_atoi(nptr));
	return (0);
}*/
