# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>

typedef struct s_node
{
	int				num;
	long long		ind;
	struct s_node	*next;
}	t_node;

long long	ps_lstsize(t_node *lst)
{
	long long		i;
	t_node	*j;

	j = lst;
	i = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	lst = j;
	return (i);
}

void rrotate(t_node **s)
{
	t_node		*tmp;
	t_node		*tmp1;
	long long	i;

	i = ps_lstsize(*s);
	tmp = *s;
	while((*s)->next)
		*s = (*s)->next;
	tmp1 = *s;
	tmp1->next = tmp;
	*s = tmp1;
	while(i > 1)
	{
		*s = (*s)->next;
		i--;
	}
	(*s)->next = NULL;
	*s = tmp1;
}

void rrotate_a(t_node **a)
{
	if(!a)
		return ;
	if((*a)->next == NULL)
		return ;
	rrotate(a);
	write(1, "rra\n", 4);
}

void rrotate_b(t_node **b)
{
	if(!b)
		return ;
	if((*b)->next == NULL)
		return ;
	rrotate(b);
	write(1, "rrb\n", 4);
}

void rrotate_rrr(t_node **a, t_node **b)
{
	if(!a)
		return ;
	if((*a)->next == NULL)
		return ;
	if(!b)
		return ;
	if((*b)->next == NULL)
		return ;
	rrotate(a);
	rrotate(b);
	write(1, "rrr\n", 4);
}

void rotate(t_node **s)
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

void rotate_a(t_node **a)
{
	if(!a)
		return ;
	if((*a)->next == NULL)
		return ;
	rotate(a);
	write(1, "ra\n", 3);
}

void rotate_b(t_node **b)
{
	if(!b)
		return ;
	if((*b)->next == NULL)
		return ;
	rotate(b);
	write(1, "rb\n", 3);
}

void rotate_rr(t_node **a, t_node **b)
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
void swap(t_node **s)
{
	t_node *tmp;
	t_node *tmp2;

	tmp = *s;
	tmp2 = (*s)->next;
	*s = (*s)->next;
	tmp->next = (*s)->next;
	tmp2->next = tmp;
	*s = tmp2;
}

void swap_a(t_node **a)
{
	if(!a)
		return ;
	if((*a)->next == NULL)
		return ;
	swap(a);
	write(1, "sa\n", 3);
}

void swap_b(t_node **b)
{
	if(!b)
		return ;
	if((*b)->next == NULL)
		return ;
	swap(b);
	write(1, "sb\n", 3);
}

void swap_ss(t_node **a, t_node **b)
{
	if(!b || !a)
		return ;
	if((*b)->next == NULL || (*a)->next == NULL)
		return ;
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}

void	push_swap_test(t_node **a, t_node **b, char *str)
{
	if(str[0] == 's' && str[1] == 'a')
		swap_a(a);
	else if(str[0] == 's' && str[1] == 'b')
		swap_b(b);
	else if(str[0] == 's' && str[1] == 's')
		swap_ss(a, b);
	else if(str[0] == 'p' && str[1] == 'a')
		push_a(a, b);
	else if(str[0] == 'p' && str[1] == 'b')
		push_b(a, b);
	else if(str[0] == 'r' && str[1] == 'a' && !str[2])
		rotate_a(a);
	else if(str[0] == 'r' && str[1] == 'b' && !str[2])
		rotate_b(b);
	else if(str[0] == 'r' && str[1] == 'r' && !str[2])
		rotate_rr(a, b);
	else if(str[0] == 'r' && str[1] == 'r' && str[2] == 'a')
		rrotate_a(a);
	else if(str[0] == 'r' && str[1] == 'r' && str[2] == 'b')
		rrotate_b(b);
	else if(str[0] == 'r' && str[1] == 'r' && str[2] == 'r')
		rrotate_rrr(a, b);
}

void	check_print_array(t_node *a, t_node *b)
{
	t_node	*j;

	j = a;
	if (!j)
	{
		write(1, "CHECK_EROR\n", 11);
		exit(1);
	}
	while (j != NULL)
	{
		printf("NUM A:%d: ", j->num);
		printf("IND A:%lld:\n", j->ind);
		j = j->next;
	}
	j = b;
	if (!j)
	{
		write(1, "CHECK_EROR\n", 11);
		exit(1);
	}
		while (j != NULL)
	{
		printf("NUM B:%d: ", j->num);
		printf("IND B:%lld:\n", j->ind);
		j = j->next;
	}
}

int main(int ac, char **av)
{
	t_node	*a;
	a = (t_node *)malloc(sizeof(t_node));
	a->num = 10;
	a->ind = 3;
	
	t_node *a2;
	a2 = (t_node *)malloc(sizeof(t_node));
	a2->num = 20;
	a2->ind = 4;

	a->next = a2;

	t_node *a3;
	a3 = (t_node *)malloc(sizeof(t_node));
	a3->num = 30;
	a3->ind = 5;

	a2->next = a3;
	a3->next = NULL;

	t_node	*b;
	b = (t_node *)malloc(sizeof(t_node));
	b->num = -10;
	b->ind = 2;
	
	t_node *b2;
	b2 = (t_node *)malloc(sizeof(t_node));
	b2->num = -20;
	b2->ind = 1;

	b->next = b2;

	t_node *b3;
	b3 = (t_node *)malloc(sizeof(t_node));
	b3->num = -30;
	b3->ind = 0;

	b2->next = b3;
	b3->next = NULL;

	push_swap_test(&a, &b, av[ac - 1]);
	check_print_array(a, b);
	exit(0);
}
