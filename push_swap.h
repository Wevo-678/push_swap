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
long	ft_atol(const char *s)

//push_swap
t_list *init_stack(char **tab, int i)
int push_swap(t_list *a)


#endif
