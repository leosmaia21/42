/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledos-sa <ledos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:44:11 by ledos-sa          #+#    #+#             */
/*   Updated: 2022/12/09 18:26:02 by ledos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPLEX_H
# define COMPLEX_H

# define SIZE 720
# include "minilibx-linux/mlx.h"

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

typedef struct complex{
	int		name;
	t_point	c;
	t_point	cord;
	double	zoom;
	t_range	range_x;
	t_range	range_y;
	int		loops;
	t_vars	*vars;
}	t_fractal;

void		pixels2cord(int x, int y, t_fractal *fractal);
int			diverge_julia(t_fractal *fractal);
int			diverge_maldelbrot(t_fractal *fractal);
double		map(double x, t_range *range);
#endif
