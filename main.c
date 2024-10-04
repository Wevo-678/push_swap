/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenet <mabenet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 12:01:24 by mabenet           #+#    #+#             */
/*   Updated: 2024/10/04 10:32:18 by mabenet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	t_stack_node *a;
	t_stack_node *b;

	int i;

	i = 1;
	a = NULL;
	b = NULL;
	
	if (ac == 2)
		{
			ac = countword(av[1]); 
			av = ft_split(av[1]);
			i = 0;
		}

	if (ac >= 2)
	{
		if(tab_checker(av, i, ac) == 1)
		{
			stack_init(&a, av, i);
			print_stack(a);
			push_swap(&a, &b);
			print_stack(a);
		}
		else if(tab_checker(av, i, ac) == 0)
			printf("Argument Error\n");
	}
	else
		printf("Besoin d'une pile de nombres en argument\n");
	return(0);
}