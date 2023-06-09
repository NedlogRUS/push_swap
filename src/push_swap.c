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
			eror_out();
	}
	return ((int)out * sign);
}

void eror_out(void)
{
	ft_putstr_fd("Eror\n", 2);
	exit (1);
}

// void check_input(char *str)
// {
// 	int i;

// 	i = 0;
// 	while(str[i++])
// 		if(!ft_isascii(str[i]))
// 			eror_out();
// }

// int *strar_to_int_ar(char **strar)
// {
// 	int *out;
// 	int i;

// 	i = 0;
// 	while(strar[i])
// 		i++;
// 	out = (int *)malloc(sizeof(int) * i + 1);
// 	if(!out)
// 		eror_out();
// 	i = -1;
// 	while(strar[++i])
// 		out[i] = ps_atoi(strar[i]);
// 	return(out);
// }

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
		eror_out();
	while(strar[i])
	{
		tmp = ps_lstnew(ps_atoi(strar[i]));
		if(!tmp)
			eror_out();
		ps_lstadd_back(&a, tmp);
		// free (tmp);
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
            eror_out();
        }
        tmp = tmp->next;
    }
    return ; // No duplicates found
}

void check_duplicates(t_node *a)
{
    t_node *tmp = a;
    
    while (tmp != NULL) 
	{
        has_duplicate(tmp->next, tmp->num);
        tmp = tmp->next;
    }
    return ; // No duplicates found
}

void ps_check(char *str)
{
	char **strar;
	t_node *a;

	a = NULL;
	strar = ft_split(str, ' ');
	if(strar[0] == NULL)
		exit (0);
	strar = check_number(strar);
	a = strar_to_node(strar, a);
	check_print_array(&a);
	write(1, "OK\n", 3);
	check_duplicates(a);
	// numar = strar_to_int_ar(strar);
	// while (strar[i])
	// 	printf("%s\n", strar[i++]);
	// write(1, "CHECK\n", 6);
	// while(numar[i])
	// 	printf("%i\n", numar[i++]);
}

void	check_print_array(t_node **a)
{
	t_node	*j;

	j = *a;
	if (!j)
	{
		write(1, "CHECK_EROR\n", 11);
		exit(1);
	}
	while (j != NULL)
	{
		printf("NUM :%d: ", j->num);
		printf("IND :%d:\n", j->ind);
		j = j->next;
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
				eror_out();
		}
		while(strar[i][j])
		{
			if(!ft_isdigit(strar[i][j]))
				eror_out();
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
		// printf("%s\n", av[ac]);
		ac++;
	}
	ps_check(str);
	// printf("%s\n", str);
	// system("leaks push_swap");
	exit (0);
}