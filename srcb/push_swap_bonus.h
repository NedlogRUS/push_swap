/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 21:14:27 by apanikov          #+#    #+#             */
/*   Updated: 2023/06/15 21:14:29 by apanikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"

typedef struct s_node
{
	int				num;
	long long		ind;
	struct s_node	*next;
}	t_node;

void		push_swap(char *str);
void		exception(t_node **a, t_node **b, int i);
t_node		*ps_lstnew(int num);
t_node		*ps_lstlast(t_node *lst);
t_node		*strar_to_node(char **strar, t_node *a);
char		*ps_strjoin(char *s1, char const *s2);
int			ps_atoi(const char *str);
void		ps_lstadd_back(t_node **lst, t_node *new);
void		has_duplicate(t_node *a, int num);
void		check_duplicates(t_node *a);
int			check_sort_a(t_node *a);
int			*strar_to_arind(char **strar);
int			counter_arind(char **strar);
int			*sort_arind(int *arind, int i);
void		ind_from_arind_to_a(t_node *a, int *arind);
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
int			sort_2_a(t_node **a);
int			sort_3(t_node **a);
int			sort_4(t_node **a, t_node **b, int i);
int			sort_3_5(t_node **a);
int			sort_5(t_node **a, t_node **b);
void		checker(t_node **a, t_node **b);
void		do_push_swap(t_node **a, t_node **b, char *str);
int			check_empty(char *strar);

#endif
