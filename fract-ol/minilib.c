/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilib.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledos-sa <ledos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 19:56:21 by ledos-sa          #+#    #+#             */
/*   Updated: 2022/12/09 18:36:03 by ledos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"
#include "minilibx-linux/mlx.h"
#include "complex.h"
#include "fractals.h"
#include <stdio.h>
#include <stdlib.h>

void	draw(int x, t_fractal *fractal);

void	move_arrows(t_fractal *fractal, int keycode)
{
	if (keycode == 65362)
	{
		fractal->range_y.max += fractal->zoom * 2 * 0.1;
		fractal->range_y.min += fractal->zoom * 2 * 0.1;
	}
	if (keycode == 65364)
	{
		fractal->range_y.max -= fractal->zoom * 2 * 0.1;
		fractal->range_y.min -= fractal->zoom * 2 * 0.1;
	}
	if (keycode == 65363)
	{
		fractal->range_x.max += fractal->zoom * 2 * 0.1;
		fractal->range_x.min += fractal->zoom * 2 * 0.1;
	}
	if (keycode == 65361)
	{
		fractal->range_x.max -= fractal->zoom * 2 * 0.1;
		fractal->range_x.min -= fractal->zoom * 2 * 0.1;
	}
}

int	key_hook(int keycode, t_fractal *fractal)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(fractal->vars->mlx, fractal->vars->win);
		exit(1);
	}
	if (keycode >= 65361 && keycode <= 65364)
	{
		move_arrows(fractal, keycode);
		draw(fractal->name, fractal);
	}
	return (0);
}

void	zoom_and_move(t_fractal *fractal, int x, int y, t_point old)
{
	t_point	new;

	fractal->range_x.min = -2 * fractal->zoom;
	fractal->range_x.max = 2 * fractal->zoom;
	fractal->range_y.min = -2 * fractal->zoom;
	fractal->range_y.max = 2 * fractal->zoom;
	new.real = map((double)x, &(fractal->range_x));
	new.imag = map((double)y, &(fractal->range_x));
	fractal->range_x.min += old.real - new.real;
	fractal->range_x.max += old.real - new.real;
	fractal->range_y.min += old.imag - new.imag;
	fractal->range_y.max += old.imag - new.imag;
}

int	mouse_hook(int button, int x, int y, t_fractal *fractal)
{
	t_point			old;

	y = SIZE - y;
	old.real = map((double)x, &(fractal->range_x));
	old.imag = map((double)y, &(fractal->range_y));
	if (button == 4)
	{
		fractal->zoom *= 0.95;
		fractal->loops += 1;
	}
	if (button == 5)
	{
		fractal->zoom /= 0.95;
		fractal->loops -= 1;
	}
	zoom_and_move(fractal, x, y, old);
	draw(fractal->name, fractal);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
