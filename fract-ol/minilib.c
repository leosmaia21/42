/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilib.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledos-sa <ledos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 19:56:21 by ledos-sa          #+#    #+#             */
/*   Updated: 2022/12/08 02:06:23 by ledos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"
#include "minilibx-linux/mlx.h"
#include "complex.h"
#include <stdio.h>

void		mandelbrot(t_vars *vars);
void		julia(t_vars *vars);
double		map(double x, t_range range);

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 27)
		mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	static double	zoom = 1;
	double			xx;
	double			yy;

	y = SIZE - y;
	if (button == 4)
	{
		vars->fractal->range_x.out_min = -2 * zoom;
		vars->fractal->range_x.out_max = 2 * zoom;
		vars->fractal->range_y.out_min = -2 * zoom;
		vars->fractal->range_y.out_max = 2 * zoom;
		xx = map((double)x, vars->fractal->range_x);
		yy = map((double)y, vars->fractal->range_x);
		vars->fractal->range_x.out_min += xx * zoom;
		vars->fractal->range_x.out_max += xx * zoom;
		vars->fractal->range_y.out_min += yy * zoom;
		vars->fractal->range_y.out_max += yy * zoom;
		zoom *= 0.95;
		printf("%f,%f,%f\n",xx,yy,zoom);
		mandelbrot(vars);
	}
	if (button == 5)
	{
		vars->fractal->range_x.out_min = -2 * zoom;
		vars->fractal->range_x.out_max = 2 * zoom;
		vars->fractal->range_y.out_min = -2 * zoom;
		vars->fractal->range_y.out_max = 2 * zoom;
		zoom /= 0.95;
		/* vars->fractal->range_x.out_min -= ((double)x / SIZE * 2 - 2) * zoom; */
		/* vars->fractal->range_x.out_max += ((double)x / SIZE * 2 - 2) * zoom; */
		/* vars->fractal->range_y.out_min -= ((double)x / SIZE * 2 - 2) * zoom; */
		/* vars->fractal->range_y.out_max += ((double)x / SIZE * 2 - 2) * zoom; */
		mandelbrot(vars);
	}
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
