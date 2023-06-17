/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 02:08:43 by apanikov          #+#    #+#             */
/*   Updated: 2023/06/15 02:08:48 by apanikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_2_a(t_node **a)
{
	if ((*a)->ind > (*a)->next->ind)
	{
		swap_a(a);
		return (1);
	}
	return (0);
}

int	sort_3(t_node **a)
{
	if ((*a)->ind == 2 && (*a)->next->ind == 0)
		rotate_a(a);
	else if ((*a)->ind == 2 && (*a)->next->ind == 1)
	{
		rotate_a(a);
		swap_a(a);
	}
	else if ((*a)->ind == 1 && (*a)->next->ind == 2)
		rrotate_a(a);
	else if ((*a)->ind == 1 && (*a)->next->ind == 0)
		swap_a(a);
	else if ((*a)->ind == 0 && (*a)->next->ind == 2)
	{
		swap_a(a);
		rotate_a(a);
	}
	return (1);
}

int	sort_4(t_node **a, t_node **b, int i)
{
	while ((*a)->ind != i - 1)
	{
		if (max_ind(*a, i) == 1)
			rotate_a(a);
		else
			rrotate_a(a);
	}
	push_b(a, b);
	(void)sort_3(a);
	push_a(a, b);
	rotate_a(a);
	return (1);
}

int	sort_3_5(t_node **a)
{
	if ((*a)->ind == 4 && (*a)->next->ind == 2)
		rotate_a(a);
	else if ((*a)->ind == 4 && (*a)->next->ind == 3)
	{
		rotate_a(a);
		swap_a(a);
	}
	else if ((*a)->ind == 3 && (*a)->next->ind == 4)
		rrotate_a(a);
	else if ((*a)->ind == 3 && (*a)->next->ind == 2)
		swap_a(a);
	else if ((*a)->ind == 2 && (*a)->next->ind == 4)
	{
		swap_a(a);
		rotate_a(a);
	}
	return (1);
}

int	sort_5(t_node **a, t_node **b)
{
	int	j;
	int	i;

	i = 2;
	j = 0;
	while (j != 2)
	{
		while ((*a)->ind != i - 1)
		{
			if (max_ind(*a, i) == 1)
				rotate_a(a);
			else
				rrotate_a(a);
		}
		push_b(a, b);
		i--;
		j++;
	}
	(void)sort_3_5(a);
	if ((*b)->ind < (*b)->next->ind)
		swap_b(b);
	push_a(a, b);
	push_a(a, b);
	return (1);
}
