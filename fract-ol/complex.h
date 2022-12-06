/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledos-sa <ledos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:44:11 by ledos-sa          #+#    #+#             */
/*   Updated: 2022/12/06 18:25:33 by ledos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPLEX_H
# define COMPLEX_H

# define SIZE 1000
# define LOOPS 1000

typedef struct complex{
	double	real;
	double	imag;	
}	t_complex;

t_complex	pixels2cord(int x, int y);
int			diverge_julia(t_complex *cord, t_complex *c);
int			diverge_maldelbrot(t_complex *cord);
#endif
