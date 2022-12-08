/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledos-sa <ledos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 12:22:13 by ledos-sa          #+#    #+#             */
/*   Updated: 2022/12/03 21:11:12 by ledos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libft/libftprintf/ft_printf.h"
#include <signal.h>

void	handler_sig(int signal, siginfo_t *info, void *ucontent)
{
	static unsigned char	c = 0;
	static int				index = 0;

	(void)ucontent;
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
		if (kill(info->si_pid, SIGUSR1) == -1)
			ft_putstr_fd("Error: Failed to send SIGUSR1\n", 2);
	}
}

int	main(void)
{
	struct sigaction	sa_newsig;

	sa_newsig.sa_sigaction = &handler_sig;
	sa_newsig.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa_newsig, NULL) == -1)
		ft_putstr_fd("Error: Failed to send SIGUSR1\n", 2);
	if (sigaction(SIGUSR2, &sa_newsig, NULL) == -1)
		ft_putstr_fd("Error: Failed to send SIGUSR1\n", 2);
	ft_printf("Server pid:%d \n", getpid());
	while (1)
	{
		pause();
	}
	return (0);
}
