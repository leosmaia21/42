/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledos-sa <ledos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:44:11 by ledos-sa          #+#    #+#             */
/*   Updated: 2022/12/09 17:57:05 by ledos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPLEX_H
# define COMPLEX_H

# define SIZE 720

typedef struct point{
	double	real;
	double	imag;
}	t_point;

typedef struct range{
	double	min;
	double	max;
}	t_range;

typedef struct complex{
	int		name;
	t_point	c;
	t_point	cord;
	double	zoom;
	t_range	range_x;
	t_range	range_y;
	int		loops;
}	t_fractal;

void		pixels2cord(int x, int y, t_fractal *fractal);
int			diverge_julia(t_fractal *fractal);
int			diverge_maldelbrot(t_fractal *fractal);
double		map(double x, t_range *range);
#endif
