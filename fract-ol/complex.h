/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledos-sa <ledos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:44:11 by ledos-sa          #+#    #+#             */
/*   Updated: 2022/12/09 15:52:33 by ledos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPLEX_H
# define COMPLEX_H

# define SIZE 720
# define LOOPS 200

typedef struct point{
	double	real;
	double	imag;
}	t_point;

typedef struct range{
	double	min;
	double	max;
}	t_range;

typedef struct complex{
	char	*name;
	t_point	c;
	t_point	cord;
	double	zoom;
	t_point	p_point;
	t_range	range_x;
	t_range	range_y;
}	t_fractal;

void		pixels2cord(int x, int y, t_fractal *fractal);
int			diverge_julia(t_fractal *fractal);
int			diverge_maldelbrot(t_fractal *fractal);
#endif
