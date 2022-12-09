/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledos-sa <ledos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:44:11 by ledos-sa          #+#    #+#             */
/*   Updated: 2022/12/09 19:10:37 by ledos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPLEX_H
# define COMPLEX_H

# include "minilibx-linux/mlx.h"
# include "fractals.h"

void		pixels2cord(int x, int y, t_fractal *fractal);
int			diverge_julia(t_fractal *fractal);
int			diverge_maldelbrot(t_fractal *fractal);
double		map(double x, t_range *range);
#endif
