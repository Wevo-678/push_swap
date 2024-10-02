/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenet <mabenet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:55:50 by mabenet           #+#    #+#             */
/*   Updated: 2024/10/02 11:09:56 by mabenet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_init(t_stack_node *a, char **av, int n)
{
	long	nbr;
	
	while (av[n])
	{
		nbr = ft_atol(av[n]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			error_free(a, av);
		if (error_repetition(*a, (int)nbr))
			error_free(a, av);
		append_node(*a, (int)nbr);
		++n;
	}
}

void	append_node(t_stack_node *stack, int nbr)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	node = malloc(sizeof(t_stack_node));
	node->next = NULL;
	node->value = nbr;
	if (NULL == *stack)
	{
		stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last_node(stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

// void push_swap(t_stack_node **a, t_stack_node **b, char **av)
// {

// }