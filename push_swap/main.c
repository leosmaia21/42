/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledos-sa <ledos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 15:49:20 by ledos-sa          #+#    #+#             */
/*   Updated: 2023/01/15 20:15:08 by ledos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "helper.h"
#include <stdlib.h>

void	bubble_sort(int *arr, int n)
{
	int	i;
	int	temp;
	int	j;

	j = 0;
	i = 0;
	while (i < n - 1)
	{
		j = 0;
		while (j < n - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	set_index(t_number *stack, int n)
{
	int			i;
	int			j;
	int			*arr;
	t_number	*temp;

	i = 0;
	j = 0;
	temp = stack;
	arr = ft_calloc(n, sizeof(int));
	while (temp)
	{
		arr[i++] = temp->number;
		temp = temp->next;
	}
	bubble_sort(arr, n);
	temp = stack;
	while (temp)
	{
		while (temp->number != arr[j])
			j++;
		temp->index = j;
		temp = temp->next;
		j = 0;
	}
}

t_number	*create_node(void)
{
	t_number	*aux;

	aux = malloc(sizeof(t_number));
	aux->next = NULL;
	return (aux);
}

int	main(int argc, char **argv)
{
	t_number	*stack_a;		
	t_number	*stack_b;		
	t_number	*temp;
	int			i;

	i = 1;
	stack_a = malloc(sizeof(t_number));
	temp = stack_a;
	temp->number = ft_atoi(argv[1]);
	while (i < argc - 1)
	{
		temp->next = create_node();
		temp = temp->next;
		temp->number = ft_atoi(argv[i + 1]);
		i++;
	}
	set_index(stack_a, argc - 1);
	stack_a = rx(stack_a);
	while (stack_a)
	{
		printf("%d\n", stack_a->number);
		stack_a = stack_a->next;
	}
}
