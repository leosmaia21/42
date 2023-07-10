/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledos-sa <ledos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 19:34:36 by ledos-sa          #+#    #+#             */
/*   Updated: 2023/07/07 22:06:25 by ledos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

uint64_t	gt(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000LL + current_time.tv_usec / 1000));
}

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

void	print(t_info *i, uint32_t type)
{
	pthread_mutex_lock(i->printmutex);
	if (*i->end == 0)
	{
		if (type == PDIED && *i->end == 0)
		{
			*i->end = 1;
			printf("%lu %d died\n", gt() - i->time[0], i->id + 1);
		}
		else if (type == PTHINK)
			printf("%lu %d is thinking\n", gt() - i->time[0], i->id + 1);
		else if (type == PEATING)
			printf("%lu %d is eating\n", gt() - i->time[0], i->id + 1);
		else if (type == PFORK)
			printf("%lu %d has taken a fork\n", gt() - i->time[0], i->id + 1);
		else if (type == PSLEEP)
			printf("%lu %d is sleeping\n", gt() - i->time[0], i->id + 1);
	}
	pthread_mutex_unlock(i->printmutex);
}

int	aux(t_info *i, int f)
{
	if (!f)
	{
		print(i, PTHINK);
		i->s = NONE;
		return (0);
	}
	else
	{
		print(i, PDIED);
		return (1);
	}
}
