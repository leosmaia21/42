/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledos-sa <ledos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:41:13 by ledos-sa          #+#    #+#             */
/*   Updated: 2023/01/15 20:16:52 by ledos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper.h"
#include <stdio.h>

t_number	*sx(t_number *stack)
{
	int		n;
	int		i;

	if (!stack->next)
		return (stack);
	n = stack->number;
	i = stack->index;
	stack->number = stack->next->number;
	stack->index = stack->next->index;
	stack->next->number = n;
	stack->next->index = i;
	return (stack);
}

t_number	*rx(t_number *stack)
{
	int			n;
	int			i;
	t_number	*t;
	t_number	*t2;

	t = stack->next;
	t2 = stack;
	while (t2->next != NULL)
		t2 = t2->next;
	t2->next = stack;
	stack->next = NULL;
	return (t);
}

void	ss(t_number *stack_a, t_number *stack_b)
{
	sx(stack_a);
	sx(stack_b);
}

void	rr(t_number *stack_a, t_number *stack_b)
{
	rx(stack_a);
	rx(stack_b);
}

t_number	*rrx(t_number *stack)
{
	int			n;
	int			i;
	t_number	*t;

	t = stack;
	while (t->next->next != NULL)
		t = t->next;
	n = stack->number;
	i = stack->index;
	stack->number = t->next->number;
	stack->index = t->next->index;
	t->next->number = n;
	t->next->index = i;
	return (stack);
}
