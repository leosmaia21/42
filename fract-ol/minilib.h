/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilib.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledos-sa <ledos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 19:55:08 by ledos-sa          #+#    #+#             */
/*   Updated: 2022/12/09 21:28:04 by ledos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINILIB_H
# define MINILIB_H

# include "fractals.h"
# include "minilibx-linux/mlx.h"

int		key_hook(int keycode, t_fractal *fractal);
int		mouse_hook(int button, int x, int y, t_fractal *fractal);
int		bye(t_vars *vars);
#endif
