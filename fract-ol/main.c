/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledos-sa <ledos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:45:12 by ledos-sa          #+#    #+#             */
/*   Updated: 2022/12/06 23:46:30 by ledos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "libft/libft.h"
#include "complex.h"
#include "minilib.h"
#include <stdio.h>
#include <string.h>

void	mandelbrot(t_data *img)
{
	int			x;
	int			y;
	t_complex	cord;
	t_point		p;

	x = -1;
	y = -1;
	p.x = 2;
	p.y = 2;
	while (++y < SIZE)
	{
		while (++x < SIZE)
		{
			cord = pixels2cord(x, y, p, 1);
			my_mlx_pixel_put(img, (int)x, (int)y, \
				0x0000f1ff * diverge_maldelbrot(&cord));
		}
		x = -1;
	}
}

void	julia(t_data *img, t_complex *c)
{
	int			x;
	int			y;
	t_complex	cord;
	t_point		p;

	x = -1;
	y = -1;
	p.x = 2;
	p.y = 2;
	while (++y < SIZE)
	{
		while (++x < SIZE)
		{
			cord = pixels2cord(x, y, p, 1);
			my_mlx_pixel_put(img, (int)x, (int)y, \
				0x0000f1ff * diverge_julia(&cord, c));
		}
		x = -1;
	}
}

void	draw(int x, t_complex c)
{
	t_vars		vars;
	t_data		img;
	t_complex	point;

	point.imag = -1;
	point.real = -1;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, SIZE, SIZE, "Hello world!");
	img.img = mlx_new_image(vars.mlx, SIZE, SIZE);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	vars.img = &img;
	if (x == 1)
		mandelbrot(&img);
	else if (x == 2)
		julia(&img, &c);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_loop(vars.mlx);
}

int	main(int argc, char **argv)
{
	t_complex	c;

	c.imag = 0;
	c.real = 0;
	if (!ft_strncmp(argv[1], "mandelbrot", 10))
		draw(1, c);
	if (!ft_strncmp(argv[1], "julia", 5) && argc != 4)
	{
		c.real = (double)ft_atoi(argv[2]);
		c.imag = (double)ft_atoi(argv[3]);
		draw(2, c);
	}
	return (0);
}
