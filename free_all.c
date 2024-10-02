/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenet <mabenet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 09:50:09 by mabenet           #+#    #+#             */
/*   Updated: 2024/10/02 11:11:47 by mabenet          ###   ########.fr       */
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

void	error_free(t_stack_node **a, char **av)
{
	free_stack(a);
	free_matrix(av);
	write(2, "Error\n", 6);
	exit(1);
}

void	free_matrix(char **av)
{
	int	i;

	i = -1;
	if (NULL == av || NULL == *av)
		return ;
	while (av[i])
		free(av[i++]);
	free(av - 1);
}


void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (NULL == stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}