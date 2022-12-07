/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilib.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledos-sa <ledos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 19:56:21 by ledos-sa          #+#    #+#             */
/*   Updated: 2022/12/07 01:10:26 by ledos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"
#include "minilibx-linux/mlx.h"
#include "complex.h"

void	mandelbrot(t_data *img, t_point p, t_vars *vars);
void	julia(t_data *img, t_complex *c, t_point p, t_vars *vars);

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 27)
		mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	static double	zoom = 1;
	t_point			p;

	p.x = 4 - (((double)x / SIZE) * 4);
	p.y = 4 - (((double)y / SIZE) * 4);
	if (button == 4)
	{
		zoom += 1.5;
		p.zoom = zoom;
		mandelbrot(vars->img, p, vars);
	}
	if (button == 5)
	{
		zoom -= 1.5;
		p.zoom = zoom;
		mandelbrot(vars->img, p, vars);
	}
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
