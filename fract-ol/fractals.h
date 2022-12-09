/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledos-sa <ledos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:59:26 by ledos-sa          #+#    #+#             */
/*   Updated: 2022/12/09 18:01:49 by ledos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTALS_H
# define FRACTALS_H

# include "minilibx-linux/mlx.h"
# include "complex.h"
# include "minilib.h"

void	mandelbrot(t_vars *vars);
void	julia(t_vars *vars);

#endif
