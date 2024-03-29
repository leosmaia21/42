/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledos-sa <ledos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 15:44:07 by ledos-sa          #+#    #+#             */
/*   Updated: 2023/01/16 22:12:39 by ledos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPER_H
# define HELPER_H

typedef struct s_number
{
	int				number;
	int				index;
	int				max;
	struct s_number	*next;
}	t_number;

void	sx(t_number **stack);
void	ss(t_number **stack_a, t_number **stack_b);
void	rx(t_number **stack);
void	rr(t_number **stack_a, t_number **stack_b);
void	rrx(t_number **stack);
#endif
