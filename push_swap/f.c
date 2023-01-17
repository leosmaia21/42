/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledos-sa <ledos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:41:13 by ledos-sa          #+#    #+#             */
/*   Updated: 2023/01/17 15:06:49 by ledos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper.h"
#include <stdio.h>

void	sx(t_number **stack)
{
	int	n;
	int	i;

	if (!(*stack)->next)
		return ;
	n = (*stack)->number;
	i = (*stack)->index;
	(*stack)->number = (*stack)->next->number;
	(*stack)->index = (*stack)->next->index;
	(*stack)->next->number = n;
	(*stack)->next->index = i;
}

void	rx(t_number **stack)
{
	int			n;
	int			i;
	t_number	*t;
	t_number	*t2;

	t = (*stack);
	t2 = (*stack);
	if (!(*stack) || (*stack)->next == NULL)
		return ;
	while (t2->next != NULL)
	{
		t2 = t2->next;
	}
	(*stack) = t->next;
	t2->next = t;
	t2->next->next = NULL;
}

/* void	ss(t_number *stack_a, t_number *stack_b) */
/* { */
/* 	sx(stack_a); */
/* 	sx(stack_b); */
/* } */

/* void	rr(t_number *stack_a, t_number *stack_b) */
/* { */
/* 	rx(stack_a); */
/* 	rx(stack_b); */
/* } */

/* t_number	*rrx(t_number *stack) */
/* { */
/* 	int			n; */
/* 	int			i; */
/* 	t_number	*t; */
/* 	t_number	*t2; */

/* 	t2 = stack; */
/* 	if (!stack || stack->next == NULL) */
/* 		return (stack); */
/* 	while (t2->next->next != NULL) */
/* 		t2 = t2->next; */
/* 	t = t2->next; */
/* 	t2->next = stack; */
/* 	t2->next = NULL; */
/* 	t->next = stack; */
/* 	return (t); */
/* } */
