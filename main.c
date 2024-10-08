/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenet <mabenet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 12:01:24 by mabenet           #+#    #+#             */
/*   Updated: 2024/10/08 11:34:53 by mabenet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lst_sorted(t_stack_node *a)
{
	while (a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

void	free_all(t_stack_node *a, t_stack_node *b, char **av, int i)
{
	if (i == 0)
		free_tab(av);
	if (a != NULL)
		free_stack(&a);
	if (b != NULL)
		free_stack(&b);
}

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;
	int				i;

	i = 1;
	a = NULL;
	b = NULL;
	if (ac == 2)
	{
		ac = countword(av[1]);
		av = ft_split(av[1]);
		i = 0;
	}
	if (ac >= 2 && tab_checker(av, i, ac) == 1 && stack_init(&a, av, i) == 1)
	{
		if (lst_sorted(a) == 0)
			push_swap(&a, &b);
	}
	else if ((ac != 1 || tab_checker(av, i , ac) == 0))
		write(1,"Error\n",6);
	free_all(a, b, av, i);
}
