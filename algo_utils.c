/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenet <mabenet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:10:03 by mabenet           #+#    #+#             */
/*   Updated: 2024/10/03 15:16:37 by mabenet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *s)
{
	long int	nb;
	int			sign;

	nb = 0;
	sign = 1;
	while ((*s == ' ' || *s == '\t' || *s == '\n') && *s !='\0')
		s++;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = (-1);
		s++;
	}
	while (*s != '\0' && (*s >= '0' && *s <= '9'))
	{
		nb = nb * 10 + *s - '0';
		s++;
	}
	return (sign * nb);
}

int	stack_len(t_stack_node *stack)
{
	int	count;

	if (NULL == stack)
		return (0);
	count = 0;
	while (stack)
	{
		++count;
		stack = stack->next;
	}
	return (count);
}

t_stack_node	*find_last_node(t_stack_node *head)
{
	if (NULL == head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

void print_stack(t_stack_node *stack)
{
	while(stack)
	{
		printf("%d\n", stack->value);
		stack = stack->next;
	}
}