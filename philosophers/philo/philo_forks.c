/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_forks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledos-sa <ledos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 19:43:10 by ledos-sa          #+#    #+#             */
/*   Updated: 2023/07/07 20:13:28 by ledos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

uint32_t	leftfork(t_info *info, uint32_t state, uint32_t g)
{
	pthread_mutex_lock(info->tforks.leftmutex);
	if (*info->tforks.leftfork == 0 && g == TAKE)
	{
		if (state == RIGHT)
			state = BOTH;
		else if (state == NONE)
			state = LEFT;
		print(info, PFORK);
		*info->tforks.leftfork = 1;
	}
	else if (g == PUTDOWN)
	{
		if (state == BOTH)
			state = RIGHT;
		else if (state == LEFT)
			state = NONE;
		*info->tforks.leftfork = 0;
	}
	pthread_mutex_unlock(info->tforks.leftmutex);
	return (state);
}

uint32_t	rightfork(t_info *info, uint32_t state, uint32_t g)
{
	pthread_mutex_lock(info->tforks.rightmutex);
	if (*info->tforks.rightfork == 0 && g == TAKE)
	{
		if (state == LEFT)
			state = BOTH;
		else if (state == NONE)
			state = RIGHT;
		print(info, PFORK);
		*info->tforks.rightfork = 1;
	}
	else if (g == PUTDOWN)
	{
		if (state == BOTH)
			state = LEFT;
		else if (state == RIGHT)
			state = NONE;
		*info->tforks.rightfork = 0;
	}
	pthread_mutex_unlock(info->tforks.rightmutex);
	return (state);
}
