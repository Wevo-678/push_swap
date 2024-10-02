/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenet <mabenet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 12:01:24 by mabenet           #+#    #+#             */
/*   Updated: 2024/09/30 13:48:08 by mabenet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	char **tab;
	int i;
	i = 1;
	
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
			//push_swap(init_stack(av)); // todo push_swap/init _stack
			while(i < ac && tab_checker(av, i, ac) == 1)
			{
				printf("%s\n", av[i]);
				i++;
			}
		}
		else if(tab_checker(av, i, ac) == 0)
		{
			printf("Argument Error\n");
		}

	}
	else
		printf("besoin d'une pile de nombres en argument\n");
	return(0);
}