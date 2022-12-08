/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledos-sa <ledos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 12:21:59 by ledos-sa          #+#    #+#             */
/*   Updated: 2022/12/03 21:11:16 by ledos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libft/libftprintf/ft_printf.h"
#include <signal.h>
#include <stdio.h>

void	send_mds(int pid, char *msg)
{
	int	c;
	int	index;

	index = 0;
	while (*msg)
	{
		c = *(msg++);
		while (index < 8)
		{
			if ((c << index) & 128)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(50);
			index++;
		}
		index = 0;
	}
}

void	handler_sig(int signal, siginfo_t *info, void *ucontent)
{
		ft_printf("Character recevido\n");
}

int	main(int argc, char *argv[])
{
	(void)argc;
	struct sigaction	sa_newsig;

	sa_newsig.sa_sigaction = &handler_sig;
	sa_newsig.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa_newsig, NULL) == -1)
		ft_putstr_fd("Error: Failed to send SIGUSR1\n", 2);
	send_mds(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
	return (0);
}
