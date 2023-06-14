# include "push_swap.h"

void error_out(void)
{
	ft_putstr_fd("Error\n", 2);
	exit (1);
}

void	check_sort_a(t_node *a)
{
	int i;

	i = 0;
	while(a)
	{
		if(a->ind != i)
			return;
		a = a->next;
		i++;
	}
	exit(0);
}

void	exception(t_node **a, t_node **b, int i)
{
	int j;

	j = 0;
	if(i == 2)
		j += sort_2_a(a);
	else if(i == 3)
		j += sort_3(a);
	else if(i == 4)
		j += sort_4(a, b, i);
	else if(i == 5)
		j += sort_5(a, b);
	if(j != 0)
	{ 
		exit(0);
	}
}

void push_swap(char *str)
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
	check_duplicates(a);
	arind = strar_to_arind(strar);
	i = counter_arind(strar);
	arind = sort_arind(arind, i);
	ind_from_arind_to_a(a, arind);
	check_sort_a(a);
	exception(&a, &b, i);
	butterfly(&a, &b, i);
	push_from_b_to_a(&a, &b, i);
	exit (0);
}

// void	check_print_array(t_node *a) // it check function
// {
// 	t_node	*j;

// 	j = a;
// 	if (!j)
// 	{
// 		write(1, "CHECK_EROR\n", 11);
// 		exit(1);
// 	}
// 	while (j != NULL)
// 	{
// 		printf("NUM :%d: ", j->num);
// 		printf("IND :%lld:\n", j->ind);
// 		j = j->next;
// 	}
// }

// void	check_print_arind(int *a, int i) // it check function
// {
// 	int j;

// 	j = 0;
// 	while(j < i)
// 	{
// 		printf("arind :%d:\n", a[j]);
// 		j++;
// 	}
// }

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
	push_swap(str);
	return(0);
}