/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledos-sa <ledos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 19:52:50 by ledos-sa          #+#    #+#             */
/*   Updated: 2023/07/07 22:08:07 by ledos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat_aux(t_info *i, uint8_t hand)
{
	if (hand == RIGHTHAND)
	{
		i->s = rightfork(i, i->s, PUTDOWN);
		i->s = leftfork(i, i->s, PUTDOWN);
	}
	else if (hand == LEFTHAND)
	{
		i->s = leftfork(i, i->s, PUTDOWN);
		i->s = rightfork(i, i->s, PUTDOWN);
	}
}

void	eat_aux2(t_info *i)
{
	if (i->timetosleep <= i->timetodie)
	{
		if (i->timetosleep + i->timetoeat > i->timetodie)
			usleep((i->timetodie - i->timetoeat) * 1000);
		else
			usleep(i->timetosleep * 1000);
	}
	else
	{
		if (i->timetoeat < i->timetosleep)
			usleep((i->timetosleep - i->timetodie) * 1000);
		else
			usleep(i->timetodie * 1000);
	}
}

uint8_t	eat(t_info *i, uint8_t hand)
{
	i->time[1] = gt();
	print(i, PEATING);
	i->buchocheio++;
	usleep(i->timetoeat * 1000);
	if (gt() - i->time[1] >= i->timetodie)
	{
		print(i, PDIED);
		*i->end = 1;
		return (DIED);
	}
	eat_aux(i, hand);
	i->s = THINKING;
	if (*i->end == 1)
		return (0);
	print(i, PSLEEP);
	eat_aux2(i);
	if (gt() - i->time[1] >= i->timetodie)
		return (DIED);
	return (ALIVE);
}

void	*philoeven(void *info)
{
	t_info		*i;

	i = (t_info *)info;
	i->time[0] = gt();
	i->time[1] = gt();
	while (*i->end == 0)
	{
		if (i->s == THINKING && gt() - i->time[1] < i->timetodie)
			aux(i, 0);
		if (gt() - i->time[1] > i->timetodie && *i->end == 0 && aux(i, 1))
			return (0);
		while (i->s == NONE && !(*i->end) && gt() - i->time[1] < i->timetodie)
			i->s = rightfork(info, i->s, TAKE);
		i->s = leftfork(info, i->s, TAKE);
		if (i->s == BOTH && eat(i, RIGHTHAND) == DIED && aux(i, 1))
			return (0);
		if (i->buchocheio == i->howmanyuntilbuchocheio)
			return (0);
	}
	return (0);
}

void	*philoodd(void *info)
{
	t_info		*i;

	i = (t_info *)info;
	i->time[0] = gt();
	i->time[1] = gt();
	while (*i->end == 0)
	{
		if (i->s == THINKING && gt() - i->time[1] < i->timetodie)
			aux(i, 0);
		if (gt() - i->time[1] > i->timetodie && aux(i, 1))
			return (0);
		while (i->s == NONE && !(*i->end) && gt() - i->time[1] < i->timetodie)
			i->s = leftfork(info, i->s, TAKE);
		i->s = rightfork(info, i->s, TAKE);
		if (i->s == BOTH && eat(i, LEFTHAND) == DIED && aux(i, 1))
			return (0);
		if (i->buchocheio == i->howmanyuntilbuchocheio)
			return (0);
	}
	return (0);
}
