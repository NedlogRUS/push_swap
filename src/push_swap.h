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

t_node		*ps_lstnew(int num);
t_node		*ps_lstlast(t_node *lst);
t_node		*strar_to_node(char **strar, t_node *a);
char		*ps_strjoin(char *s1, char const *s2);
int			ps_atoi(const char *str);
int			ps_atoi(const char *str);
void		ps_lstadd_back(t_node **lst, t_node *new);
void		has_duplicate(t_node *a, int num);
void		check_duplicates(t_node *a);
int			*strar_to_arind(char **strar);
int			counter_arind(char **strar);
int			*sort_arind(int *arind, int i);
void		ind_from_arind_to_a(t_node *a, int *arind);
void		ps_check(char *str);
char		**check_number(char **strar);
void		error_out(void);
void		push(t_node **f, t_node **s);
void		push_a(t_node **a, t_node **b);
void		push_b(t_node **a, t_node **b);
void		swap(t_node **s);
void		swap_a(t_node **a);
void		swap_b(t_node **b);
void		swap_ss(t_node **a, t_node **b);
void		rotate(t_node **s);
void		rotate_a(t_node **a);
void		rotate_b(t_node **b);
void		rotate_rr(t_node **a, t_node **b);
long long	ps_lstsize(t_node *lst);
void		rrotate(t_node **s);
void		rrotate_a(t_node **a);
void		rrotate_b(t_node **b);
void		rrotate_rrr(t_node **a, t_node **b);

void		check_print_array(t_node *a); // it check function
void		check_print_arind(int *a, int i); // it check function

#endif