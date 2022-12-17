/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledos-sa <ledos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 12:21:59 by ledos-sa          #+#    #+#             */
/*   Updated: 2022/12/17 17:54:20 by ledos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
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

int	main(int argc, char *argv[])
{
	(void)argc;
	send_mds(ft_atoi(argv[1]), argv[2]);
	return (0);
}
