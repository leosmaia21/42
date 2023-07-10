/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledos-sa <ledos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 19:33:29 by ledos-sa          #+#    #+#             */
/*   Updated: 2023/07/07 22:27:51 by ledos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdatomic.h>
# include <stdint.h>
# include <stdio.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_forks{
	uint32_t		*leftfork;
	uint32_t		*rightfork;
	pthread_mutex_t	*leftmutex;
	pthread_mutex_t	*rightmutex;
}	t_forks;

typedef struct s_info{
	t_forks			tforks;
	int32_t			numberofphilos;
	uint32_t		id;
	uint32_t		timetodie;
	uint32_t		timetoeat;
	uint32_t		timetosleep;
	uint32_t		s;
	uint64_t		time[2];
	atomic_int		*end;
	int32_t			buchocheio;
	int32_t			howmanyuntilbuchocheio;
	pthread_mutex_t	*printmutex;
	atomic_int		*start;
	int32_t			i;
}	t_info;

# define BOTH 3
# define LEFT 2
# define RIGHT 1
# define NONE 0
# define THINKING 4
# define PUTDOWN 0
# define TAKE 1
# define LEFTHAND 0
# define RIGHTHAND 1
# define DIED 1
# define ALIVE 0

# define PDIED 0
# define PSLEEP 1
# define PEATING 2
# define PTHINK 3
# define PFORK 4

uint64_t	gt(void);
int32_t		ft_atoi(const char *nptr);
void		print(t_info *i, uint32_t type);
void		init(t_info *info, char **argv, pthread_mutex_t *mutex, int argc);
int			aux(t_info *i, int f);
void		threads(t_info *i, uint32_t *f, pthread_t *pt, pthread_mutex_t *m);
uint32_t	leftfork(t_info *info, uint32_t state, uint32_t g);
uint32_t	rightfork(t_info *info, uint32_t state, uint32_t g);
uint8_t		eat(t_info *i, uint8_t hand);
void		*philoeven(void *info);
void		*philoodd(void *info);
int			check_argums(int var, char **str);

#endif
