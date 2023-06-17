/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 02:07:54 by apanikov          #+#    #+#             */
/*   Updated: 2023/06/15 02:07:58 by apanikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	butterfly(t_node **a, t_node **b, int i)
{
	int	j;
	int	n;

	j = 0;
	n = size_of_range(i);
	while (*a && j < i)
	{
		if ((*a)->ind <= j)
		{
			push_b(a, b);
			rotate_b(b);
		j++;
		}
		else if ((*a)->ind <= j + n)
		{
			push_b(a, b);
			j++;
		}
		else
			rotate_a(a);
	}
}

void	push_from_b_to_a(t_node **a, t_node **b, int i)
{
	while (i > 0)
	{
		while ((*b)->ind != i - 1)
		{
			if (max_ind(*b, i) == 1)
				rotate_b(b);
			else
				rrotate_b(b);
		}
		push_a(a, b);
		i--;
	}
}

int	size_of_range(int i)
{
	int	j;

	j = 1;
	while (j * j < i * 2)
		j++;
	return (j);
}

int	max_ind(t_node *s, int i)
{
	t_node	*tmp;

	tmp = s;
	while (tmp->ind != 0)
	{
		if (tmp->ind == i - 1)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
