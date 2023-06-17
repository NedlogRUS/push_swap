/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 21:13:58 by apanikov          #+#    #+#             */
/*   Updated: 2023/06/15 21:13:59 by apanikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	error_out(void)
{
	ft_putstr_fd("Error\n", 2);
	exit (1);
}

void	do_push_swap(t_node **a, t_node **b, char *to_do)
{
	if (ft_strcmp(to_do, "sa\n") == 0)
		swap_a(a);
	else if (ft_strcmp(to_do, "sb\n") == 0)
		swap_b(b);
	else if (ft_strcmp(to_do, "ss\n") == 0)
		swap_ss(a, b);
	else if (ft_strcmp(to_do, "pa\n") == 0)
		push_a(a, b);
	else if (ft_strcmp(to_do, "pb\n") == 0)
		push_b(a, b);
	else if (ft_strcmp(to_do, "ra\n") == 0)
		rotate_a(a);
	else if (ft_strcmp(to_do, "rb\n") == 0)
		rotate_b(b);
	else if (ft_strcmp(to_do, "rr\n") == 0)
		rotate_rr(a, b);
	else if (ft_strcmp(to_do, "rra\n") == 0)
		rrotate_a(a);
	else if (ft_strcmp(to_do, "rrb\n") == 0)
		rrotate_b(b);
	else if (ft_strcmp(to_do, "rrr\n") == 0)
		rrotate_rrr(a, b);
	else
		error_out();
}

void	checker(t_node **a, t_node **b)
{
	char	*to_do;

	while (1)
	{
		to_do = get_next_line(0);
		if (!to_do)
			break ;
		do_push_swap(a, b, to_do);
		free(to_do);
	}
	if (check_sort_a(*a) == 1 && !*b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	exit(0);
}

void	push_swap(char *str)
{
	char	**strar;
	int		*arind;
	int		i;
	t_node	*a;
	t_node	*b;

	i = 0;
	a = NULL;
	b = NULL;
	arind = NULL;
	strar = ft_split(str, ' ');
	if (strar[0] == NULL)
		exit(0);
	strar = check_number(strar);
	a = strar_to_node(strar, a);
	check_duplicates(a);
	arind = strar_to_arind(strar);
	i = counter_arind(strar);
	arind = sort_arind(arind, i);
	ind_from_arind_to_a(a, arind);
	checker(&a, &b);
}

int	main(int ac, char **av)
{
	char	*str;

	if (ac <= 1)
		exit(0);
	ac = 1;
	if (check_empty(av[ac]) == 1)
		error_out();
	str = ft_strdup(av[ac++]);
	while (av[ac])
	{
		if (check_empty(av[ac]) == 1)
			error_out();
		str = ps_strjoin(str, av[ac]);
		ac++;
	}
	push_swap(str);
	return (0);
}
