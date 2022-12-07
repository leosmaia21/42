/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledos-sa <ledos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:44:11 by ledos-sa          #+#    #+#             */
/*   Updated: 2022/12/07 00:10:22 by ledos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPLEX_H
# define COMPLEX_H

# define SIZE 720
# define LOOPS 150

typedef struct complex{
	double	real;
	double	imag;	
}	t_complex;

typedef struct point{
	double	x;
	double	y;
	double	zoom;
}	t_point;

t_complex	pixels2cord(int x, int y, t_point p);
int			diverge_julia(t_complex *cord, t_complex *c);
int			diverge_maldelbrot(t_complex *cord);
#endif
