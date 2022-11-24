/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledos-sa <ledos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:27:52 by ledos-sa          #+#    #+#             */
/*   Updated: 2022/11/24 19:55:58 by ledos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_printstr("(null)"));
	while (s[i])
		write(1, &s[i++], 1);
	return (i);
}

int	ft_format(va_list args, char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += printchar(va_arg(args, int));
	else if (c == 's')
		len += ft_printstr(va_arg(args, char *));
	else if (c == 'p')
		len += ft_printptr(va_arg(args, unsigned long long));
	else if (c == 'i' || c == 'd')
		ft_put_nbr((va_arg(args, int)), &len, 0);
	else if (c == 'u')
		ft_put_nbr((va_arg(args, int)), &len, 1);
	else if (c == 'x' || c == 'X')
		ft_put_hex((va_arg(args, unsigned int)), &len, c);
	else if (c == '%')
		len += printchar('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start(args, str);
	va_end(args);
	while (*str)
	{
		if (*str == '%')
			len += ft_format(args, *(++str));
		else
			len += printchar(*str);
		str++;
	}
	va_end(args);
	return (len);
}

/* int main(int argc, char *argv[]) */
/* { */
/* 	int x = -10; */
/* 	int len; */
/* 	char s[]="olai"; */
/* 	len =ft_printf("%p",15); */
/* 	/1* len= ft_printf("%s\n",s); *1/ */
/* 	/1* ft_printf("%d",len); *1/ */
/* 	/1* printf("%p\n",15); *1/ */
/* 	return 0; */
/* } */
