/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 21:14:19 by apanikov          #+#    #+#             */
/*   Updated: 2023/06/15 21:14:20 by apanikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_node	*strar_to_node(char **strar, t_node *a)
{
	int		i;
	t_node	*tmp;

	i = 0;
	a = ps_lstnew(ps_atoi(strar[i++]));
	if (!a)
		error_out();
	while (strar[i])
	{
		tmp = ps_lstnew(ps_atoi(strar[i]));
		if (!tmp)
			error_out();
		ps_lstadd_back(&a, tmp);
		i++;
	}	
	return (a);
}

void	has_duplicate(t_node *a, int num)
{
	t_node	*tmp;

	tmp = a;
	while (tmp != NULL)
	{
		if (tmp->num == num)
			error_out();
		tmp = tmp->next;
	}
}

void	check_duplicates(t_node *a)
{
	t_node	*tmp;

	tmp = a;
	while (tmp != NULL)
	{
		has_duplicate(tmp->next, tmp->num);
		tmp = tmp->next;
	}
}

int	*strar_to_arind(char **strar)
{
	int	i;
	int	*out;

	i = 0;
	while (strar[i])
		i++;
	out = (int *)malloc(sizeof(int) * i);
	if (!out)
		error_out();
	i = 0;
	while (strar[i])
	{
		out[i] = ps_atoi(strar[i]);
		i++;
	}
	return (out);
}

char	**check_number(char **strar)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (strar[i])
	{
		j = 0;
		if (strar[i][0] == '-')
		{
			j++;
			if (!strar[i][j])
				error_out();
		}
		while (strar[i][j])
		{
			if (!ft_isdigit(strar[i][j]))
				error_out();
			j++;
		}
		i++;
	}
	return (strar);
}
