/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 02:09:07 by apanikov          #+#    #+#             */
/*   Updated: 2023/06/15 02:09:09 by apanikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node **s)
{
	t_node	*tmp;
	t_node	*tmp2;

	tmp = *s;
	tmp2 = (*s)->next;
	*s = (*s)->next;
	tmp->next = (*s)->next;
	tmp2->next = tmp;
	*s = tmp2;
}

void	swap_a(t_node **a)
{
	if (!*a)
		return ;
	if ((*a)->next == NULL)
		return ;
	swap(a);
	write(1, "sa\n", 3);
}

void	swap_b(t_node **b)
{
	if (!*b)
		return ;
	if ((*b)->next == NULL)
		return ;
	swap(b);
	write(1, "sb\n", 3);
}

void	swap_ss(t_node **a, t_node **b)
{
	if (!*b || !*a)
		return ;
	if ((*b)->next == NULL || (*a)->next == NULL)
		return ;
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
