/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledos-sa <ledos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:45:12 by ledos-sa          #+#    #+#             */
/*   Updated: 2022/12/06 17:08:39 by ledos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "libft/libft.h"
#include <math.h>
#include "complex.h"

typedef struct	s_data {
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
	int	x;
	int y;

	/* cord = pixels2cord(100, 500 ); */
	/* printf("%f, %f", cord.real, cord.imag); */
	y = -1;
	x = -1;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, SIZE, SIZE, "Hello world!");
	img.img = mlx_new_image(mlx, SIZE, SIZE);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	while (++y < SIZE)
	{
		while (++x < SIZE)
		{
			cord = pixels2cord(x, y);
			my_mlx_pixel_put(&img, x, y, 0xccf1ff * diverge_maldelbrot(&cord));
		}
		x = -1;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
