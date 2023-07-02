/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledos-sa <ledos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 17:03:27 by ledos-sa          #+#    #+#             */
/*   Updated: 2023/07/01 21:02:38 by ledos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>
#include <sys/wait.h>

#define BOTH 3
#define LEFT 2
#define RIGHT 1
#define NONE 0
#define THINKING 4

typedef struct s_info{
	int32_t		timetodie;
	int32_t		timetoeat;
	int32_t		timetosleep;
	uint64_t	time[2];
	uint32_t	state;
	uint32_t	id;

}	t_info;

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

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000LL + current_time.tv_usec / 1000));
}

uint32_t	checkifdied(t_info i)
{
	if (gt() - i.time[1] > i.timetodie)
	{
		printf("%lu %d is thinking\n", gt() - i.time[0], i.id + 1);
		return (1);
	}
	return (0);
}

void	philo(sem_t *sem, t_info i)
{
	while (1)
	{
		if (gt() - i.time[1] < i.timetodie)
		{
			i.time[1] = gt();
			printf("%lu %d is thinking\n", gt() - i.time[0], i.id + 1);
		}
		if (checkifdied(i) == 1)
			return ;
		sem_wait(sem);
		printf("%lu %d has taken a fork\n", gt() - i.time[0], i.id + 1);
		if (checkifdied(i) == 1)
			return ;
		sem_wait(sem);
		printf("%lu %d has taken a fork\n", gt() - i.time[0], i.id + 1);
		if (checkifdied(i) == 1)
			return ;
		i.time[1] = gt();
		printf("%lu %d is eating\n", gt() - i.time[0], i.id + 1);
		usleep(i.timetoeat * 1000);
		sem_post(sem);
		sem_post(sem);
		usleep(i.timetosleep * 1000);
		if (checkifdied(i) == 1) 
			return ;
	}
}

int	main(int argc, char **argv)
{
	int32_t		numberofforks;
	t_info		info;
	sem_t		sem;
	int32_t		i;
	uint32_t	forkid;

	int value;
	forkid = 1;
	numberofforks = ft_atoi(argv[1]);
	// sem = sem_open("thisnuts", O_CREAT, 0644, numberofforks);
	sem_init(&sem, 1, numberofforks);
	sem_getvalue(&sem, &value);
	printf("value:%d\n", value);
	// exit(1);
	info.timetodie = ft_atoi(argv[2]);
	info.timetoeat = ft_atoi(argv[3]);
	info.timetosleep = ft_atoi(argv[4]);
	info.time[0] = gt();
	info.time[1] = gt();
	i = -1;
	while (++i < numberofforks && forkid != 0)
		forkid = fork();
	info.id = i;
	info.state = THINKING;
	if (forkid == 0)
		philo(&sem, info);
	while(waitpid(-1, NULL, 0) > 0);
}
