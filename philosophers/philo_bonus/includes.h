/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledos-sa <ledos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 21:11:24 by ledos-sa          #+#    #+#             */
/*   Updated: 2023/07/09 22:12:55 by ledos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_H
# define INCLUDES_H

# define THINK 1
# define EAT 2
# define SLEEP 3
# define FORK 4

# include <errno.h>
# include <signal.h>
# include <stdatomic.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <semaphore.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <errno.h>
# include <sys/wait.h>

typedef struct s_info{
	uint64_t			timetodie;
	uint64_t			timetoeat;
	uint64_t			timetosleep;
	uint64_t			time[2];
	uint32_t			state;
	uint32_t			id;
	uint32_t			*pid;
	_Atomic uint64_t	lasteat;
	uint32_t			philos;
	sem_t				*psem;
	sem_t				*end;
	sem_t				*sem;
	int					timestoeat;
	atomic_int			ate;

}	t_info;

int32_t		ft_atoi(const char *nptr);
uint64_t	gt(void);
void		*checkdied(void	*info);
void		print(t_info *i, int type);
#endif
