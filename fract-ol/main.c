/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledos-sa <ledos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:45:12 by ledos-sa          #+#    #+#             */
/*   Updated: 2022/12/09 18:03:03 by ledos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "libft/libft.h"
#include "complex.h"
#include "minilib.h"
#include "fractals.h"
#include <stdio.h>
#include <string.h>

void	draw(int x, t_fractal *fractal)
{
	t_vars		vars;
	t_data		img;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, SIZE, SIZE, "Hello world!");
	img.img = mlx_new_image(vars.mlx, SIZE, SIZE);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	vars.img = &img;
	vars.fractal = fractal;
	if (x == 1)
		mandelbrot(&vars);
	else if (x == 2)
		julia(&vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_loop(vars.mlx);
}


int	main(int argc, char **argv)
{
	t_fractal	fractal;

	(void)argc;
	fractal.c.imag = 0;
	fractal.c.real = 0;
	fractal.zoom = 1;
	fractal.range_x.min = -2;
	fractal.range_x.max = 2;
	fractal.range_y.min = -2;
	fractal.range_y.max = 2;
	fractal.loops = 200;
	if (!ft_strncmp(argv[1], "mandelbrot", 10))
	{
		fractal.name = 1;
		draw(1, &fractal);
	}
	if (!ft_strncmp(argv[1], "julia", 5))
	{
		fractal.name = 2;
		fractal.c.real = (double)ft_atoi(argv[2]);
		fractal.c.imag = (double)ft_atoi(argv[3]);
		draw(2, &fractal);
	}
	return (0);
}
