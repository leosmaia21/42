/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilib.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledos-sa <ledos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 19:56:21 by ledos-sa          #+#    #+#             */
/*   Updated: 2022/12/07 15:29:32 by ledos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"
#include "minilibx-linux/mlx.h"
#include "complex.h"

void	mandelbrot(t_vars *vars);
void	julia(t_vars *vars);

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

	xx = (double)x / SIZE - 2;
	yy = (double)y / SIZE - 2;
	if (button == 4)
	{
		zoom *= 1.5;
		vars->fractal->zoom = zoom;
		mandelbrot(vars);
	}
	if (button == 5)
	{
		zoom /= 1.5;
		vars->fractal->zoom = zoom;
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
