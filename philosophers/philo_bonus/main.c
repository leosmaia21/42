/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledos-sa <ledos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 17:03:27 by ledos-sa          #+#    #+#             */
/*   Updated: 2023/07/09 22:07:06 by ledos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

void	*checkdied(void	*info)
{
	t_info	*i;

	i = (t_info *)info;
	while (1)
	{
		if (gt() - i->lasteat > i->timetodie)
		{
			sem_wait(i->psem);
			printf("%lu %d died\n", gt() - i->time[0], i->id + 1);
			sem_post(i->end);
		}
		if (i->timestoeat == i->ate)
			sem_post(i->end);
	}
	return (0);
}

void	philo(t_info *i)
{
	pthread_t	t;

	i->lasteat = gt();
	pthread_create(&t, NULL, checkdied, i);
	while (1)
	{
		print(i, THINK);
		sem_wait(i->sem);
		print(i, FORK);
		sem_wait(i->sem);
		print(i, FORK);
		print(i, EAT);
		i->ate++;
		i->lasteat = gt();
		usleep(i->timetoeat * 1000);
		sem_post(i->sem);
		sem_post(i->sem);
		print(i, SLEEP);
		usleep(i->timetosleep * 1000);
		usleep(i->timetodie - i->timetoeat - i->timetosleep / 2);
	}
}

void	init(t_info *info, int argc, char **argv, int32_t *numberofforks)
{
	*numberofforks = ft_atoi(argv[1]);
	info->pid = malloc(*numberofforks * 4);
	sem_unlink("sem");
	sem_unlink("psem");
	sem_unlink("end");
	info->sem = sem_open("sem", O_CREAT, 0600, *numberofforks);
	info->psem = sem_open("psem", O_CREAT, 0600, 1);
	info->end = sem_open("end", O_CREAT, 0600, 0);
	info->timetodie = ft_atoi(argv[2]);
	info->timetoeat = ft_atoi(argv[3]);
	info->timetosleep = ft_atoi(argv[4]);
	info->id = -1;
	info->time[0] = gt();
	info->ate = 0;
	if (argc == 6)
		info->timestoeat = ft_atoi(argv[5]);
	else 
		info->timestoeat = -1;
}

int	main(int argc, char **argv)
{
	int32_t		numberofforks;
	t_info		info;
	int32_t		i;
	uint32_t	forkid;

	forkid = -1;
	init(&info, argc, argv, &numberofforks);
	i = -1;
	while (++i < numberofforks && forkid != 0)
	{
		forkid = fork();
		if (forkid != 0)
			info.pid[i] = forkid;
	}
	info.id = i - 1;
	if (forkid == 0)
		philo(&info);
	else
	{
		sem_wait(info.end);
		i = -1;
		while (++i < numberofforks)
			kill(info.pid[i], SIGTERM);
		waitpid(-1, NULL, 0);
	}
}
