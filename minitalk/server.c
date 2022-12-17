/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledos-sa <ledos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 12:22:13 by ledos-sa          #+#    #+#             */
/*   Updated: 2022/12/17 18:22:19 by ledos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libft/libftprintf/ft_printf.h"
#include <signal.h>

void	handler_sig(int signal)
{
	static unsigned char	c = 0;
	static int				index = 0;

	if (signal == SIGUSR1)
		c = (c << 1) | 1;
	if (signal == SIGUSR2)
		c = c << 1;
	index++;
	if (index == 8)
	{
		ft_printf("%c", c);
		c = 0;
		index = 0;
	}
}

int	main(void)
{
	ft_printf("Server pid:%d \n", getpid());
	while (1)
	{
		signal(SIGUSR1, handler_sig);
		signal(SIGUSR2, handler_sig);
	}
	return (0);
}
