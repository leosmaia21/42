/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledos-sa <ledos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 19:51:30 by ledos-sa          #+#    #+#             */
/*   Updated: 2023/07/07 20:10:34 by ledos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_aux(atomic_int **end, pthread_mutex_t **mprint, atomic_int **start)
{
	*end = malloc(sizeof(atomic_int *));
	*start = malloc(sizeof(atomic_int *));
	*mprint = malloc(sizeof(pthread_mutex_t *));
	**end = 0;
	**start = 0;
}

void	init(t_info *info, char **argv, pthread_mutex_t *mutex, int argc)
{
	atomic_int		*end;
	pthread_mutex_t	*mprint;
	atomic_int		*start;

	info->i = -1;
	init_aux(&end, &mprint, &start);
	while (++(info->i) < ft_atoi(argv[1]))
	{
		pthread_mutex_init(&mutex[info->i], NULL);
		info[info->i].timetodie = ft_atoi(argv[2]);
		info[info->i].timetoeat = ft_atoi(argv[3]);
		info[info->i].timetosleep = ft_atoi(argv[4]);
		info[info->i].numberofphilos = ft_atoi(argv[1]);
		info[info->i].end = end;
		info[info->i].printmutex = mprint;
		info[info->i].start = start;
		if (argc == 6)
		{
			info[info->i].howmanyuntilbuchocheio = ft_atoi(argv[5]);
			info[info->i].buchocheio = 0;
		}
		else 
			info[info->i].howmanyuntilbuchocheio = -1;
	}
}

void	threads(t_info *info, uint32_t *f, pthread_t *pt, pthread_mutex_t *m)
{
	int32_t		left;

	info->i = -1;
	while (++(info->i) < info->numberofphilos)
	{
		left = (info->i) - 1;
		if (info->i == 0)
			left = info->numberofphilos - 1;
		f[info->i] = 0;
		info[info->i].id = info->i;
		info[info->i].s = THINKING;
		info[info->i].tforks.leftfork = f + left;
		info[info->i].tforks.leftmutex = m + left;
		info[info->i].tforks.rightfork = f + info->i;
		info[info->i].tforks.rightmutex = m + info->i;
	}
	info->i = -1;
	while (++(info->i) < info->numberofphilos)
	{
		if ((info->i) % 2 == 0)
			pthread_create(&pt[info->i], NULL, philoeven, &info[info->i]);
		else
			pthread_create(&pt[info->i], NULL, philoodd, &info[info->i]);
	}
	*info[0].start = 1;
}
