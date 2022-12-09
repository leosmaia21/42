/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledos-sa <ledos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:48:06 by ledos-sa          #+#    #+#             */
/*   Updated: 2022/12/09 16:24:18 by ledos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "complex.h"
#include <math.h>

double	map(double x, t_range *range)
{
	return (x * (range->max - range->min) / (SIZE - 1) + range->min);
}

void	pixels2cord(int x, int y, t_fractal *fractal)
{
	y = SIZE - y;
	fractal->cord.real = map(x, &fractal->range_x);
	fractal->cord.imag = map(y, &fractal->range_y);
}

int	diverge_julia(t_fractal *fractal)
{
	int			i;
	double		module;
	double		aux;
	t_point		new_point;

	new_point.real = fractal->cord.real;
	new_point.imag = fractal->cord.imag;
	i = 0;
	while (++i < fractal->loops)
	{
		aux = new_point.real;
		new_point.real = (new_point.real * new_point.real) - \
			(new_point.imag * new_point.imag) + fractal->c.real;
		new_point.imag = (2 * aux * new_point.imag) + fractal->c.imag;
		module = (new_point.real * new_point.real) + \
			(new_point.imag * new_point.imag);
		if (module > 4)
			return (i);
	}
	return (0);
}

int	diverge_maldelbrot(t_fractal *fractal)
{
	int			i;
	double		module;
	double		aux;
	t_point		new_point;

	new_point.real = 0;
	new_point.imag = 0;
	i = 0;
	while (++i < fractal->loops)
	{
		aux = new_point.real;
		new_point.real = (new_point.real * new_point.real) - \
			(new_point.imag * new_point.imag) + fractal->cord.real;
		new_point.imag = (2 * aux * new_point.imag) + fractal->cord.imag;
		module = (new_point.real * new_point.real) + \
			(new_point.imag * new_point.imag);
		if (module > 4)
			return (i);
	}
	return (0);
}
