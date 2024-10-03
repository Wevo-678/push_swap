/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenet <mabenet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:55:50 by mabenet           #+#    #+#             */
/*   Updated: 2024/10/03 15:31:36 by mabenet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	stack_init(t_stack_node *a, char **av, int n)
// {
// 	long	nbr;
// 	t_stack_node *tmp;

// 	tmp = a;
// 	printf("%p\n", &a);
// 	while (av[n])
// 	{
// 		nbr = ft_atol(av[n]);
// 		if (nbr > INT_MAX || nbr < INT_MIN)
// 			error_free(a, av);
// 		if (error_repetition(a, (int)nbr))
// 			error_free(a, av);
// 		append_node(&a, (int)nbr);
// 		printf("%d\n", a->value);
// 		++n;
// 	}
// 	a = tmp;
// 	printf("%p\n", &a);
// }

void	stack_init(t_stack_node **a, char **av, int n)
{
	long	nbr;

	//printf("Adresse initiale du pointeur a: %p\n", (void *)a);
	while (av[n])
	{
		nbr = ft_atol(av[n]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			error_free(*a);
		if (error_repetition(*a, (int)nbr))
			error_free(*a);
		append_node(a, (int)nbr); // On passe le double pointeur ici
		//printf("Valeur du dernier nœud ajouté: %d\n", (*a)->value); // Affichage de la valeur ajoutée
		++n;
	}
	//printf("Adresse finale du pointeur a: %p\n", (void *)a);
}


// void	append_node(t_stack_node *stack, int nbr)
// {
// 	t_stack_node	*node;
// 	t_stack_node	*last_node;

// 	node = malloc(sizeof(t_stack_node));
// 	node->next = NULL;
// 	node->value = nbr;
// 	printf("int nbr = %d\n", nbr);
// 	printf("node nbr %d\n", node->value);
	
// 	if (NULL == stack)
// 	{
// 		stack = node;
// 		node->prev = NULL;
// 	}
// 	else
// 	{
// 		last_node = find_last_node(stack);
// 		last_node->next = node;
// 		node->prev = last_node;
// 	} 
// }

void	append_node(t_stack_node **stack, int nbr)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	node = malloc(sizeof(t_stack_node));
	if (!node)
		return; // Toujours vérifier si malloc a réussi

	node->next = NULL;
	node->value = nbr;
	printf("int nbr = %d\n", nbr);
	printf("node nbr %d\n", node->value);
	
	if (NULL == *stack)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	} 
}


// void push_swap(t_stack_node **a, t_stack_node **b, char **av)
// {

// }