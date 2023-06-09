#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h> // CHEK

typedef struct s_node
{
	int				num;
	long long		ind;
	struct s_node	*next;
}	t_node;

char **check_number(char **strar);
void error_out(void);
t_node	*ps_lstlast(t_node *lst);
void	check_print_array(t_node *a); // it check function
void	check_print_arind(int *a, int i); // it check function

#endif