/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledos-sa <ledos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:45:12 by ledos-sa          #+#    #+#             */
/*   Updated: 2023/01/22 19:50:56 by ledos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "libft/libft.h"
#include "complex.h"
#include "minilib.h"
#include "fractals.h"
#include "libftprintf/ft_printf.h"
#include <math.h>

void	draw(int x, t_fractal *fractal)
{
	if (x == 1)
		mandelbrot(fractal);
	else if (x == 2)
		julia(fractal);
	else if (x == 3)
		burning_ship(fractal);
	mlx_loop(fractal->vars->mlx);
}

void	init(t_fractal *fractal)
{
	fractal->zoom = 1;
	fractal->range_x.min = -2;
	fractal->range_x.max = 2;
	fractal->range_y.min = -2;
	fractal->range_y.max = 2;
	fractal->loops = 100;
	fractal->color = 0x0000f1ff;
	fractal->vars->mlx = mlx_init();
	fractal->vars->win = mlx_new_window(fractal->vars->mlx, SIZE, SIZE,
			"Fract-ol");
	fractal->vars->img->img = mlx_new_image(fractal->vars->mlx, SIZE, SIZE);
	fractal->vars->img->addr = mlx_get_data_addr(fractal->vars->img->img,
			&fractal->vars->img->bits_per_pixel,
			&fractal->vars->img->line_length,
			&fractal->vars->img->endian);
	mlx_key_hook(fractal->vars->win, key_hook, fractal);
	mlx_mouse_hook(fractal->vars->win, mouse_hook, fractal);
	mlx_hook(fractal->vars->win, 17, 0, bye, fractal->vars);
}

double	atof(const char *s)
{
	double	a;
	int		e;
	int		negative;

	a = 0.0;
	e = 0;
	negative = *s == '-';
	if (*s == '-')
		s++;
	while (*s != '\0' && ft_isdigit(*s))
		a = a * 10.0 + (*s++ - '0');
	if (*s++ == '.')
	{
		while (*s != '\0' && ft_isdigit(*s))
		{
			a = a * 10.0 + (*s++ - '0');
			e++;
		}
	}
	a = a * (1.0 / pow(10, e));
	if (negative)
		a *= -1;
	return (a);
}

void	print(int argc, char **argv)
{
	if (argc > 1)
	{
		if (!ft_strncmp(argv[1], "mandelbrot", 10) && argc == 2)
			return ;
		if (!ft_strncmp(argv[1], "julia", 5) && argc == 4)
			return ;
		if (!ft_strncmp(argv[1], "burning_ship", 12) && argc == 2)
			return ;
	}
	ft_printf("Valores de entrada errados\n");
	ft_printf("Sets disponíveis: mandelbrot, julia, burning_ship\n");
	ft_printf("Se for julia, adicionar o ponto\n");
	ft_printf("Ex: ./fract-ol julia -0.7269 0.1889\n");
	exit(1);
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;
	t_vars		vars;
	t_data		img;

	fractal.vars = &vars;
	fractal.vars->img = &img;
	print(argc, argv);
	init(&fractal);
	if (!ft_strncmp(argv[1], "mandelbrot", ft_strlen(argv[1])))
	{
		fractal.name = 1;
		draw(1, &fractal);
	}
	if (!ft_strncmp(argv[1], "julia", ft_strlen(argv[1])))
	{
		fractal.name = 2;
		fractal.c.real = atof(argv[2]);
		fractal.c.imag = atof(argv[3]);
		draw(2, &fractal);
	}
	if (!ft_strncmp(argv[1], "burning_ship", ft_strlen(argv[1])))
	{
		fractal.name = 3;
		draw(3, &fractal);
	}
}
