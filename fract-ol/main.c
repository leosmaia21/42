/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledos-sa <ledos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:45:12 by ledos-sa          #+#    #+#             */
/*   Updated: 2022/12/06 18:33:28 by ledos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "libft/libft.h"
#include <math.h>
#include "complex.h"

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main(void)
{
	void		*mlx;
	void		*mlx_win;
	t_data		img;
	t_complex	cord;
	t_complex	point;
	t_complex	julia;

	julia.real = -0.8;
	julia.imag = 0.156;
	point.imag = -1;
	point.real = -1;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, SIZE, SIZE, "Hello world!");
	img.img = mlx_new_image(mlx, SIZE, SIZE);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	while (++point.imag < SIZE)
	{
		while (++point.real < SIZE)
		{
			cord = pixels2cord(point.real, point.imag);
			my_mlx_pixel_put(&img, (int)point.real, (int)point.imag, \
				0x0000f1ff * diverge_maldelbrot(&cord));
			/* my_mlx_pixel_put(&img, (int)point.real, (int)point.imag, \ */
			/* 	0x0000f1ff * diverge_julia(&cord, &julia)); */
		}
		point.real = -1;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
