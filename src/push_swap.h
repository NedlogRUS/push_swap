#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h> // CHEK

typedef struct s_node
{
	int				num;
	unsigned int	ind;
	struct s_node	*next;
}	t_node;

char **check_number(char **strar);
void eror_out(void);
t_node	*ps_lstlast(t_node *lst);
void	check_print_array(t_node **a);

#endif