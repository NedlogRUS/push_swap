# include "push_swap.h"

void	rotate(t_node **s)
{
	t_node *tmp;
	t_node *tmp1;

	tmp = *s;
	tmp1 = (*s)->next;
	while((*s)->next)
		*s = (*s)->next;
	(*s)->next = tmp;
	tmp->next = NULL;
	*s = tmp1;
}

void	rotate_a(t_node **a)
{
	if(!a)
		return ;
	if((*a)->next == NULL)
		return ;
	rotate(a);
	write(1, "ra\n", 3);
}

void	rotate_b(t_node **b)
{
	if(!b)
		return ;
	if((*b)->next == NULL)
		return ;
	rotate(b);
	write(1, "rb\n", 3);
}

void	rotate_rr(t_node **a, t_node **b)
{
	if(!a)
		return ;
	if((*a)->next == NULL)
		return ;
	if(!b)
		return ;
	if((*b)->next == NULL)
		return ;
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}