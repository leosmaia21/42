/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledos-sa <ledos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 13:56:39 by ledos-sa          #+#    #+#             */
/*   Updated: 2023/07/07 22:23:53 by ledos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all(t_info **info, uint32_t **forks, pthread_t **pt)
{
	free(*pt);
	free(*forks);
	free((*info)->end);
	free((*info)->start);
	free((*info)->printmutex);
	free((*info));
}

int	main(int argc, char **argv)
{
	t_info			*info;
	int32_t			i;
	uint32_t		*forks;
	pthread_t		*philosthreads;
	pthread_mutex_t	*mutex;

	if (argc == 5 || argc == 6)
	{
		if (check_argums(argc, argv))
			return (1);
		info = malloc(ft_atoi(argv[1]) * sizeof(t_info));
		forks = malloc(ft_atoi(argv[1]) * sizeof(uint32_t));
		mutex = malloc(ft_atoi(argv[1]) * sizeof(pthread_mutex_t));
		philosthreads = malloc(ft_atoi(argv[1]) * sizeof(pthread_t));
		init(info, argv, mutex, argc);
		threads(info, forks, philosthreads, mutex);
		i = -1;
		while (++i < ft_atoi(argv[1]))
			pthread_join(philosthreads[i], NULL);
		free(mutex);
		free_all(&info, &forks, &philosthreads);
	}
	else
		printf("Error: wrong number of arguments\n");
	return (0);
}
