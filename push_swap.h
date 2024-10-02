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

int str_checker(char *s);
int tab_checker(char **tab, int i, int count);
int countword(char *s);
int wordlen(char *s, int i);
char **ft_split(char *s);

//algo_utils
long	ft_atol(const char *s);
int	stack_len(t_stack_node *stack);
t_stack_node	*find_last_node(t_stack_node *head);

//free_all

int		error_repetition(t_stack_node *a, int nbr);
void	error_free(t_stack_node *a, char **av);
void	free_matrix(char **av);
void	free_stack(t_stack_node **stack);


//push_swap
void	stack_init(t_stack_node *a, char **av, int n);
void push_swap(t_stack_node *a);
void	append_node(t_stack_node *stack, int nbr);



#endif
