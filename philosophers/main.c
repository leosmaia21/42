/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledos-sa <ledos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 13:56:39 by ledos-sa          #+#    #+#             */
/*   Updated: 2023/07/02 13:45:28 by ledos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>

typedef struct s_forks{
	uint32_t		*leftfork;
	uint32_t		*rightfork;
	pthread_mutex_t	*leftmutex;
	pthread_mutex_t	*rightmutex;
}	t_forks;

typedef struct s_info{
	t_forks			tforks;
	uint32_t		numberofphilos;
	uint32_t		id;
	uint32_t		timetodie;
	uint32_t		timetoeat;
	uint32_t		timetosleep;
	uint32_t		state;
	uint64_t		time[2];
	uint32_t		*end;
}	t_info;

#define BOTH 3
#define LEFT 2
#define RIGHT 1
#define NONE 0
#define THINKING 4
#define PUTDOWN 0
#define TAKE 1
#define LEFTHAND 0
#define RIGHTHAND 1
#define DIED 1
#define ALIVE 0

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

uint32_t	leftfork(t_info *info, uint32_t state, uint32_t g, uint64_t time[])
{
	pthread_mutex_lock(info->tforks.leftmutex);
	if (*info->tforks.leftfork == 0 && g == TAKE)
	{
		if (state == RIGHT)
			state = BOTH;
		else if (state == NONE)
			state = LEFT;
		printf("%lu %d has taken a left fork\n", gt() - time[0], info->id + 1);
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

uint32_t	rightfork(t_info *info, uint32_t state, uint32_t g, uint64_t time[])
{
	pthread_mutex_lock(info->tforks.rightmutex);
	if (*info->tforks.rightfork == 0 && g == TAKE)
	{
		if (state == LEFT)
			state = BOTH;
		else if (state == NONE)
			state = RIGHT;
		printf("%lu %d has taken a right fork\n", gt() - time[0], info->id + 1);
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

uint8_t	eat(t_info *i, uint8_t hand)
{
	printf("%lu %d is eating\n", gt() - i->time[0], i->id + 1);
	usleep(i->timetoeat * 1000);
	i->time[1] = gt();
	if (hand == RIGHTHAND)
	{
		i->state = rightfork(i, i->state, PUTDOWN, i->time);
		i->state = leftfork(i, i->state, PUTDOWN, i->time);
	}
	else if (hand == LEFTHAND)
	{
		i->state = leftfork(i, i->state, PUTDOWN, i->time);
		i->state = rightfork(i, i->state, PUTDOWN, i->time);
	}
	i->state = THINKING;
	if (*i->end == 1)
		return (0);
	printf("%lu %d is sleeping\n", gt() - i->time[0], i->id + 1);
	i->time[1] = gt();
	if (i->timetosleep <= i->timetodie)
		usleep(i->timetosleep * 1000);
	else
		usleep(i->timetodie * 1000);
	if (gt() - i->time[1] >= i->timetodie)
		return (DIED);
	return (ALIVE);
}

void	*philoeven(void *info)
{
	t_info		*i;

	i = (t_info *)info;
	while (*i->end == 0)
	{
		if (i->state == THINKING && gt() - i->time[1] < i->timetodie)
		{
			i->time[1] = gt();
			printf("%lu %d is thinking\n", gt() - i->time[0], i->id + 1);
			i->state = NONE;
		}
		if (gt() - i->time[1] > i->timetodie)
		{
			printf("%lu %d died\n", gt() - i->time[0], i->id + 1);
			*i->end = 1;
			return (0);
		}
		i->state = rightfork(info, i->state, TAKE, i->time);
		i->state = leftfork(info, i->state, TAKE, i->time);
		if (i->state == BOTH && eat(i, RIGHTHAND) == DIED)
		{
			printf("%lu %d died\n", gt() - i->time[0], i->id + 1);
			return (0);
		}
	}
	return (0);
}

void	*philoodd(void *info)
{
	t_info		*i;

	i = (t_info *)info;
	while (*i->end == 0)
	{
		if (i->state == THINKING && gt() - i->time[1] < i->timetodie)
		{
			i->time[1] = gt();
			printf("%lu %d is thinking\n", gt() - i->time[0], i->id + 1);
			i->state = NONE;
		}
		if (gt() - i->time[1] > i->timetodie)
		{
			printf("%lu %d died\n", gt() - i->time[0], i->id + 1);
			*i->end = 1;
			return (0);
		}
		i->state = leftfork(info, i->state, TAKE, i->time);
		i->state = rightfork(info, i->state, TAKE, i->time);
		if (i->state == BOTH && eat(i, LEFTHAND) == DIED)
		{
			printf("%lu %d died\n", gt() - i->time[0], i->id + 1);
			return (0);
		}
	}
	return (0);
}

void	threads(t_info *info, uint32_t *forks, pthread_t *philosthreads, pthread_mutex_t *mutex)
{
	int32_t		left;
	uint32_t	i;

	i = -1;
	while (++i < info->numberofphilos)
	{
		left = i - 1;
		if (i == 0)
			left = info->numberofphilos - 1;
		forks[i] = 0;
		info[i].id = i;
		info[i].state = THINKING;
		info[i].tforks.leftfork = forks + left;
		info[i].tforks.leftmutex = mutex + left;
		info[i].tforks.rightfork = forks + i;
		info[i].tforks.rightmutex = mutex + i;
	}
	i = -1;
	while (++i < info->numberofphilos)
	{
		if (i % 2 == 0)
			pthread_create(&philosthreads[i], NULL, philoeven, &info[i]);
		else
			pthread_create(&philosthreads[i], NULL, philoodd, &info[i]);
	}
}

void	init(t_info *info, char **argv, pthread_mutex_t *mutex)
{
	int32_t			i;
	uint32_t		*end;

	i = -1;
	end = malloc(sizeof(uint32_t));
	*end = 0;
	while (++i < ft_atoi(argv[1]))
	{
		pthread_mutex_init(&mutex[i], NULL);
		info[i].timetodie = ft_atoi(argv[2]);
		info[i].timetoeat = ft_atoi(argv[3]);
		info[i].timetosleep = ft_atoi(argv[4]);
		info[i].numberofphilos = ft_atoi(argv[1]);
		info[i].time[0] = gt();
		info[i].time[1] = gt();
		info[i].end = end;

	}
}

int	main(int argc, char **argv)
{
	t_info			*info;
	int32_t			i;
	uint32_t		*forks;
	pthread_t		*philosthreads;
	pthread_mutex_t	*mutex;

	(void)argc;
	info = malloc(ft_atoi(argv[1]) * sizeof(t_info));
	forks = malloc(ft_atoi(argv[1]) * sizeof(uint32_t));
	mutex = malloc(ft_atoi(argv[1]) * sizeof(pthread_mutex_t));
	philosthreads = malloc(ft_atoi(argv[1]) * sizeof(pthread_t));
	init(info, argv, mutex);
	threads(info, forks, philosthreads, mutex);
	i = -1;
	while (++i < ft_atoi(argv[1]))
		pthread_join(philosthreads[i], NULL);
	free(info->end);
	free(info);
	free(forks);
	free(philosthreads);
	free(mutex);
}
