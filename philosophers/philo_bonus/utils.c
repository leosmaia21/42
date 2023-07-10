/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledos-sa <ledos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 21:14:31 by ledos-sa          #+#    #+#             */
/*   Updated: 2023/07/09 22:07:13 by ledos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int32_t	ft_atoi(const char *nptr)
{
	int32_t	i;
	int32_t	c;
	int32_t	res;
	int32_t	n;

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

uint64_t	gt(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, 0);
	return ((current_time.tv_sec * 1000LL + current_time.tv_usec / 1000));
}

void	print(t_info *i, int type)
{
	sem_wait(i->psem);
	if (type == EAT)
		printf("%lu %d is eating\n", gt() - i->time[0], i->id + 1);
	else if (type == FORK)
		printf("%lu %d has taken a fork\n", gt() - i->time[0], i->id + 1);
	else if (type == SLEEP)
		printf("%lu %d is sleeping\n", gt() - i->time[0], i->id + 1);
	else if (type == THINK)
		printf("%lu %d is thinking\n", gt() - i->time[0], i->id + 1);
	sem_post(i->psem);
}
