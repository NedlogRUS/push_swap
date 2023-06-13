# include "push_swap.h"

void error_out(void)
{
	ft_putstr_fd("Error\n", 2);
	exit (1);
}

void	push_swap(t_node **a, t_node **b, int i)
{
	int j;
	int n;

	j = 0;
	n = 1;
	while(*a && j < i)
	{
		if((*a)->ind <= j)
		{
		push_b(a, b);
		rotate_b(b);
		j++;
		}
		else if((*a)->ind <= j + n)
		{
			push_b(a, b);
			j++;
		}
		else
			rotate_a(a);
	}
	check_print_array(*b);
	// while(*b && i > 0)
	// {
	// 	if((*b)->ind <= j)

}

void ps_check(char *str)
{
	char **strar;
	int *arind;
	int i;
	t_node *a;
	t_node *b;

	i = 0;
	a = NULL;
	b = NULL;
	arind = NULL;
	strar = ft_split(str, ' ');
	if(strar[0] == NULL)
		exit (0);
	strar = check_number(strar);
	a = strar_to_node(strar, a);
	// check_print_array(a);
	check_duplicates(a);
	arind = strar_to_arind(strar);
	i = counter_arind(strar);
	arind = sort_arind(arind, i);
	// check_print_arind(arind, i);
	ind_from_arind_to_a(a, arind);
	// int x = 0;
	// while(strar[x])
	// {
	// 	free(strar[x]);
	// 	x++;
	// }
	// free(strar);
	// free(arind);
	check_print_array(a);
	push_swap(&a, &b, i);
	// system("leaks push_swap");
	exit (0);
}

void	check_print_array(t_node *a) // it check function
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
		printf("NUM :%d: ", j->num);
		printf("IND :%lld:\n", j->ind);
		j = j->next;
	}
}

void	check_print_arind(int *a, int i) // it check function
{
	int j;

	j = 0;
	while(j < i)
	{
		printf("arind :%d:\n", a[j]);
		j++;
	}
}

int main (int ac, char **av)
{
	char *str;

	if (ac <= 1)
		exit (1);
	ac = 1;
	str = ft_strdup(av[ac++]);
	while (av[ac])
	{
		if(!check_number(&av[ac]))
			error_out();
		str = ps_strjoin(str, av[ac]);
		ac++;
	}
	ps_check(str);
	// exit (0);
	return(0);
}