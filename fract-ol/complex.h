/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledos-sa <ledos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:44:11 by ledos-sa          #+#    #+#             */
/*   Updated: 2022/12/06 23:44:23 by ledos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPLEX_H
# define COMPLEX_H

# define SIZE 720
# define LOOPS 400

typedef struct complex{
	double	real;
	double	imag;	
}	t_complex;

typedef struct point{
	double	x;
	double	y;
}	t_point;

t_complex	pixels2cord(int x, int y, t_point p, double zoom);
int			diverge_julia(t_complex *cord, t_complex *c);
int			diverge_maldelbrot(t_complex *cord);
#endif
