/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledos-sa <ledos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 22:09:35 by ledos-sa          #+#    #+#             */
/*   Updated: 2022/11/08 02:45:24 by ledos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

void
	ft_putnbr_fd(int n, int fd)
{
	char	str[13];
	int		is_neg;
	int		length;

	is_neg = (n < 0);
	ft_bzero(str, 13);
	if (n == 0)
		str[0] = '0';
	length = 0;
	while (n != 0)
	{
		str[length++] = '0' + ft_abs(n % 10);
		n = (n / 10);
	}
	if (is_neg)
		str[length] = '-';
	else if (length > 0)
		length--;
	while (length >= 0)
		write(fd, &str[length--], 1);
}
/* int	ft_number_dig(int n) */
/* { */
/* 	int r; */
/* 	int	div; */

/* 	div = 1; */
/* 	n = 0; */
/* 	while (n / div) */
/* 	{ */
/* 		div = div * 10; */
/* 		r++; */
/* 	} */
/* 	return (r); */
/* } */

/* void	ft_putnbr_fd(int n, int fd) */
/* { */
/* 	char	*s; */
/* 	int		r; */

/* 	r = ft_number_dig(n); */
/* 	while (r) */
/* 	{ */

/* 	} */
/* } */
