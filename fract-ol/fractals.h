/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledos-sa <ledos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:59:26 by ledos-sa          #+#    #+#             */
/*   Updated: 2022/12/09 19:10:03 by ledos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTALS_H
# define FRACTALS_H

# include "minilibx-linux/mlx.h"
# define SIZE 720

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_vars {
	void		*mlx;
	void		*win;
	t_data		*img;
}				t_vars;

typedef struct point{
	double	real;
	double	imag;
}	t_point;

typedef struct range{
	double	min;
	double	max;
}	t_range;

typedef struct fractal{
	int		name;
	t_point	c;
	t_point	cord;
	double	zoom;
	t_range	range_x;
	t_range	range_y;
	int		loops;
	t_vars	*vars;
	long	color;
}	t_fractal;
void	mandelbrot(t_fractal *fractal);
void	julia(t_fractal *fractal);

#endif
