# include "push_swap.h"

char	*ps_strjoin(char *s1, char const *s2)
{
	char	*res;
	int		a;
	int		b;

	a = 0;
	b = 0;
	if (!s1 || !s2)
		return ((char *)malloc(sizeof(char)));
	res = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 2) * sizeof(char));
	if (!res)
		return ((void *)0);
	while (s1[a])
	{
		res[a] = s1[a];
		a++;
	}
	res[a++] = ' ';
	while (s2[b])
		res[a++] = s2[b++];
	free (s1);
	res[a] = '\0';
	return (res);
}

int	ps_atoi(const char *str)
{
	long long	out;
	int		sign;
	int		i;

	out = 0;
	sign = 1;
	i = 0;
	while (str[i] == 32 || (str[i] > 8 && str[i] < 14))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		out = out * 10 + str[i] - '0';
		i++;
		if (!(out * sign >= -2147483648 && out * sign <= 2147483647))
			error_out();
	}
	return ((int)out * sign);
}

void error_out(void)
{
	ft_putstr_fd("Error\n", 2);
	exit (1);
}

t_node	*ps_lstnew(int num)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (0);
	new->num = num;
	new->ind = -1;
	new->next = NULL;
	return (new);
}

void	ps_lstadd_back(t_node **lst, t_node *new)
{
	if (*lst)
		ps_lstlast(*lst)->next = new;
	else
		*lst = new;
}

t_node	*ps_lstlast(t_node *lst)
{
	t_node	*j;

	j = lst;
	if (!j)
		return (0);
	while (j->next != 0)
		j = j->next;
	return (j);
}

t_node *strar_to_node(char **strar, t_node *a)
{
	int i;
	t_node *tmp;

	i = 0;
	a = ps_lstnew(ps_atoi(strar[i++]));
	if(!a)
		error_out();
	while(strar[i])
	{
		tmp = ps_lstnew(ps_atoi(strar[i]));
		if(!tmp)
			error_out();
		ps_lstadd_back(&a, tmp);
		i++;
	}	
	return(a);
}

void has_duplicate(t_node *a, int num)
{
    t_node *tmp = a;
    
    while (tmp != NULL) {
        if (tmp->num == num) 
		{
			write(1, "FIND_DUPLICATE\n", 15);
            error_out();
        }
        tmp = tmp->next;
    }
}

void check_duplicates(t_node *a)
{
    t_node *tmp = a;
    
    while (tmp != NULL) 
	{
        has_duplicate(tmp->next, tmp->num);
        tmp = tmp->next;
    }
}

int	*strar_to_arind(char **strar)
{
	int i;
	int *out;

	i = 0;
	while(strar[i])
		i++;
	out = (int *)malloc(sizeof(int) * i);
	if(!out)
		error_out();
	i = 0;
	while(strar[i])
	{
		out[i] = ps_atoi(strar[i]);
		i++;
	}
	return(out);
}

int	counter_arind(char **strar)
{
	int i;

	i = 0;
	while(strar[i])
		i++;
	return(i);
}

int *sort_arind(int *arind, int i)
{
	int j;
	int buf;

	j = -1;
	while(j < i)
	{
		j++;
		if((j + 1) < i && arind[j] > arind[j + 1])
		{
			buf = arind[j];
			arind[j] = arind[j + 1];
			arind[j + 1] = buf;
			j = -1;
		}
	}
	return(arind);
}

void	ind_from_arind_to_a(t_node *a, int *arind)
{
	t_node *tmp = a;
	int j;
	int x;

    j = 0;
	x = 0;
	while (tmp != NULL)
	{
		if(tmp->ind == -1) 
		{
			while(arind[j] != tmp->num)
				j++;
			tmp->ind = j;
			j = 0;
			tmp = a;
			x = 1;
		}
		if(x == 0)
			tmp = tmp->next;
		else
			x = 0;
	}
}

void ps_check(char *str)
{
	char **strar;
	int *arind;
	int i;
	t_node *a;

	i = 0;
	a = NULL;
	arind = NULL;
	strar = ft_split(str, ' ');
	if(strar[0] == NULL)
		exit (0);
	strar = check_number(strar);
	a = strar_to_node(strar, a);
	check_print_array(a);
	check_duplicates(a);
	arind = strar_to_arind(strar);
	i = counter_arind(strar);
	arind = sort_arind(arind, i);
	check_print_arind(arind, i);
	ind_from_arind_to_a(a, arind);
	int x = 0;
	while(strar[x])
	{
		free(strar[x]);
		x++;
	}
	free(strar);
	free(arind);
	check_print_array(a);
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

char **check_number(char **strar)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(strar[i])
	{
		j = 0;
		if(strar[i][0] == '-')
		{
			j++;
			if(!strar[i][j])
				error_out();
		}
		while(strar[i][j])
		{
			if(!ft_isdigit(strar[i][j]))
				error_out();
			j++;
		}
		i++;
	}
	return(strar);
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
		str = ps_strjoin(str, av[ac]);
		ac++;
	}
	ps_check(str);
	system("leaks push_swap");
	// exit (0);
	return(0);
}