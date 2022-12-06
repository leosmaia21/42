/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledos-sa <ledos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:48:06 by ledos-sa          #+#    #+#             */
/*   Updated: 2022/12/06 17:09:12 by ledos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "complex.h"
#include <math.h>

t_complex	pixels2cord(int x, int y)
{
	const double		max = SIZE * 0.7 / 2.0;
	t_complex			cord;	

	if (y <= SIZE / 2)
		cord.imag = ((SIZE / 2.0) - y) * 2.0 / max;
	else
		cord.imag = -((y - (SIZE / 2.0)) * 2.0 / max);
	if (x <= SIZE / 2)
		cord.real = -((SIZE / 2.0) - x) * 2.0 / max;
	else
		cord.real = ((x - (SIZE / 2.0)) * 2.0 / max);
	return (cord);
}

int	diverge_maldelbrot(t_complex *cord)
{
	int			i;
	double		module;
	t_complex	new_point;

	new_point.real = 0;
	new_point.imag = 0;
	i = 0;
	while (++i < LOOPS)
	{
		new_point.real = (new_point.real * new_point.real) - (new_point.imag * new_point.imag) + cord->real;
		new_point.imag = (2 * new_point.real * new_point.imag) + cord->imag;
		module = sqrt((new_point.real * new_point. real) + (new_point.imag * new_point.imag));
		if (module > 2.0)
			return (i);
	}
	return (0);
}
