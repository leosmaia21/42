/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledos-sa <ledos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 18:07:44 by ledos-sa          #+#    #+#             */
/*   Updated: 2022/11/24 19:44:33 by ledos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "stdarg.h"
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>

int		printchar(char c);
int		ft_printptr(unsigned long long p);
void	ft_put_nbr(unsigned int value, int *l, int unsig);
void	ft_put_hex(unsigned int value, int *l, int upper);
int		ft_printf(const char *str, ...);
int		ft_format(va_list args, char c);
int		ft_printstr(char *s);
#endif
