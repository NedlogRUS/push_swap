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

char	*ps_strjoin(char *s1, char const *s2);
int	ps_atoi(const char *str);
int	ps_atoi(const char *str);
t_node	*ps_lstnew(int num);
t_node	*ps_lstlast(t_node *lst);
t_node *strar_to_node(char **strar, t_node *a);
void	ps_lstadd_back(t_node **lst, t_node *new);
void has_duplicate(t_node *a, int num);
void check_duplicates(t_node *a);
int	*strar_to_arind(char **strar);
int	counter_arind(char **strar);
int *sort_arind(int *arind, int i);
void	ind_from_arind_to_a(t_node *a, int *arind);
void ps_check(char *str);
char **check_number(char **strar);
void error_out(void);

void	check_print_array(t_node *a); // it check function
void	check_print_arind(int *a, int i); // it check function

#endif