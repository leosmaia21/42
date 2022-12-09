/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledos-sa <ledos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:58:11 by ledos-sa          #+#    #+#             */
/*   Updated: 2022/12/09 17:58:49 by ledos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "complex.h"
#include "minilib.h"
#include "minilibx-linux/mlx.h"

void	mandelbrot(t_vars *vars)
{
	int			x;
	int			y;

	x = -1;
	y = -1;
	while (++y < SIZE)
	{
		while (++x < SIZE)
		{
			pixels2cord(x, y, vars->fractal);
			my_mlx_pixel_put(vars->img, (int)x, (int)y, \
				0x0000f1ff * diverge_maldelbrot(vars->fractal));
			vars->fractal->cord.real = 0;
			vars->fractal->cord.imag = 0;
		}
		x = -1;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
}

void	julia(t_vars *vars)
{
	int			x;
	int			y;

	x = -1;
	y = -1;
	while (++y < SIZE)
	{
		while (++x < SIZE)
		{
			pixels2cord(x, y, vars->fractal);
			my_mlx_pixel_put(vars->img, (int)x, (int)y, \
				0x0000f1ff * diverge_julia(vars->fractal));
		}
		x = -1;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
}
