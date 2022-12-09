/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledos-sa <ledos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:58:11 by ledos-sa          #+#    #+#             */
/*   Updated: 2022/12/09 21:26:29 by ledos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "complex.h"
#include "fractals.h"
#include "minilib.h"
#include "minilibx-linux/mlx.h"

void	mandelbrot(t_fractal *fractal)
{
	int			x;
	int			y;

	x = -1;
	y = -1;
	while (++y < SIZE)
	{
		while (++x < SIZE)
		{
			pixels2cord(x, y, fractal);
			my_mlx_pixel_put(fractal->vars->img, x, y, \
				fractal->color * diverge_maldelbrot(fractal));
			fractal->cord.real = 0;
			fractal->cord.imag = 0;
		}
		x = -1;
	}
	mlx_put_image_to_window(fractal->vars->mlx, fractal->vars->win,
		fractal->vars->img->img, 0, 0);
}

void	julia(t_fractal *fractal)
{
	int			x;
	int			y;

	x = -1;
	y = -1;
	while (++y < SIZE)
	{
		while (++x < SIZE)
		{
			pixels2cord(x, y, fractal);
			my_mlx_pixel_put(fractal->vars->img, x, y, \
				fractal->color * diverge_julia(fractal));
		}
		x = -1;
	}
	mlx_put_image_to_window(fractal->vars->mlx, fractal->vars->win,
		fractal->vars->img->img, 0, 0);
}

void	burning_ship(t_fractal *fractal)
{
	int			x;
	int			y;

	x = -1;
	y = -1;
	while (++y < SIZE)
	{
		while (++x < SIZE)
		{
			pixels2cord(x, y, fractal);
			my_mlx_pixel_put(fractal->vars->img, x, y, \
				fractal->color * diverge_burning_ship(fractal));
		}
		x = -1;
	}
	mlx_put_image_to_window(fractal->vars->mlx, fractal->vars->win,
		fractal->vars->img->img, 0, 0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
