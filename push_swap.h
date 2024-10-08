/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenet <mabenet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 08:25:40 by mabenet           #+#    #+#             */
/*   Updated: 2024/10/08 11:07:39 by mabenet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>

// stack

typedef struct s_stack_node
{
	int					value;
	int					current_position;
	int					final_index;
	int					push_price;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

// parse_utils

int				str_checker(char *s);
int				tab_checker(char **tab, int i, int count);
int				countword(char *s);
int				wordlen(char *s, int i);
char			**ft_split(char *s);

//algo_utils
long			ft_atol(const char *s);
int				stack_len(t_stack_node *stack);
t_stack_node	*find_last_node(t_stack_node *head);
void			print_stack(t_stack_node *stack);
void			init_nodes(t_stack_node *a, t_stack_node *b);

//free_all

int				error_repetition(t_stack_node *a, int nbr);
void			error_free(t_stack_node *a);
void			free_matrix(char **av);
void			free_stack(t_stack_node **stack);
void			free_tab(char **tab);

//sort_utils
t_stack_node	*find_highest(t_stack_node *stack);
t_stack_node	*find_smallest(t_stack_node *stack);
t_stack_node	*return_cheapest(t_stack_node *stack);
void			set_price(t_stack_node *a, t_stack_node *b);
void			set_cheapest(t_stack_node *b);

//sort
int				stack_init(t_stack_node **a, char **av, int n);
void			push_swap(t_stack_node **a, t_stack_node **b);
void			append_node(t_stack_node **stack, int nbr);
void			tiny_sort(t_stack_node **a);
void			handle_five(t_stack_node **a, t_stack_node **b);

//node 

void			move_nodes(t_stack_node **a, t_stack_node **b);
void			finish_rotation(t_stack_node **stack,
					t_stack_node	*top_node, char stack_name);
void			set_current_position(t_stack_node *stack);
void			set_target_node(t_stack_node *a,
					t_stack_node *b);

//push
void			push(t_stack_node **dest, t_stack_node **src);
void			pa(t_stack_node **a, t_stack_node **b, bool checker);
void			pb(t_stack_node **b, t_stack_node **a, bool checker);

//r_rotate
void			reverse_rotate(t_stack_node **stack);
void			rra(t_stack_node **a, bool checker);
void			rrb(t_stack_node **b, bool checker);
void			rrr(t_stack_node **a, t_stack_node **b, bool checker);
void			reverse_rotate_both(t_stack_node **a,
					t_stack_node **b, t_stack_node *cheapest_node);

//rotate
void			rotate(t_stack_node **stack);
void			ra(t_stack_node **a, bool checker);
void			rb(t_stack_node **b, bool checker);
void			rr(t_stack_node **a, t_stack_node **b, bool checker);
void			rotate_both(t_stack_node **a,
					t_stack_node **b, t_stack_node *cheapest_node);

//swap
void			swap(t_stack_node **head);
void			sa(t_stack_node	**a, bool checker);
void			sb(t_stack_node **b, bool checker);
void			ss(t_stack_node **a, t_stack_node **b, bool checker);

#endif
