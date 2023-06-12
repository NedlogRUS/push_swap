# include "push_swap.h"

void push(t_node **f, t_node **s)
{
	t_node *tmp;
	t_node *tmp1;

	tmp = *f;
	tmp1 = *s;
	*f = (*f)->next;
	tmp->next = tmp1;
	*s = tmp;
}

void push_a(t_node **a, t_node **b)
{
	if(!b)
		return ;
	push(b, a);
	write(1, "pa\n", 3);
}

void push_b(t_node **a, t_node **b)
{
	if(!a)
		return ;
	push(a, b);
	write(1, "pb\n", 3);
}