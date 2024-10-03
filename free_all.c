/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenet <mabenet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 09:50:09 by mabenet           #+#    #+#             */
/*   Updated: 2024/10/03 17:45:01 by mabenet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_repetition(t_stack_node *a, int nbr)
{
	if (NULL == a)
		return (0);
	while (a)
	{
		if (a->value == nbr)
			return (1);
		a = a->next;
	}
	return (0);
}

void	error_free(t_stack_node *a )
{
	free_stack(&a);
	write(2, "Error repetition\n", 17);
	exit(1);
}

// void	free_matrix(char **av)
// {
// 	i = -1;
// 	if (NULL == av || NULL == *av)
// 		return ;
// 	while (av[i])
// 		free(av[i++]);
// 	free(av - 1);
// }

// void	free_matrix(char **av) //bonne version
// {
// 	int	i;

// 	if (NULL == av || NULL == *av)
// 		return ;
// 	i = 0;  // Commencer à 0
// 	while (av[i])  // Parcourir chaque chaîne
// 	{
// 		free(av[i]);
// 		i++;
// 	}
// 	free(av);  // Libérer le tableau de pointeurs lui-même
// }


// void	free_stack(t_stack_node **stack)
// {
// 	t_stack_node	*tmp;
// 	t_stack_node	*current;

// 	if (NULL == stack)
// 		return ;
// 	current = *stack;
// 	while (current)
// 	{
// 		tmp = current->next;
// 		free(current);
// 		current = tmp;
// 	}
// 	stack = NULL;
// }

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (NULL == stack || NULL == *stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;  // Met à jour le pointeur original dans la fonction appelante
}
