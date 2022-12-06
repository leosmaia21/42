/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledos-sa <ledos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:48:06 by ledos-sa          #+#    #+#             */
/*   Updated: 2022/12/06 23:46:31 by ledos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "complex.h"
#include <math.h>

t_complex	pixels2cord(int x, int y, t_point p, double zoom)
{
	t_complex			cord;	

	cord.real = (((double)x / SIZE) * 4 / zoom) - p.x;
	cord.imag = (((double)y / SIZE) * 4 / zoom) - p.y;
	return (cord);
}

int	diverge_julia(t_complex *cord, t_complex *c)
{
	int			i;
	double		module;
	double		aux;
	t_complex	new_point;

	new_point.real = cord->real;
	new_point.imag = cord->imag;
	i = 0;
	while (++i < LOOPS)
	{
		aux = new_point.real;
		new_point.real = (new_point.real * new_point.real) - \
			(new_point.imag * new_point.imag) + c->real;
		new_point.imag = (2 * aux * new_point.imag) + c->imag;
		module = (new_point.real * new_point.real) + \
			(new_point.imag * new_point.imag);
		if (module > 4)
			return (i);
	}
	return (0);
}

int	diverge_maldelbrot(t_complex *cord)
{
	int			i;
	double		module;
	double		aux;
	t_complex	new_point;

	new_point.real = 0;
	new_point.imag = 0;
	i = 0;
	while (++i < LOOPS)
	{
		aux = new_point.real;
		new_point.real = (new_point.real * new_point.real) - \
			(new_point.imag * new_point.imag) + cord->real;
		new_point.imag = (2 * aux * new_point.imag) + cord->imag;
		module = (new_point.real * new_point.real) + \
			(new_point.imag * new_point.imag);
		if (module > 4)
			return (i);
	}
	return (0);
}
