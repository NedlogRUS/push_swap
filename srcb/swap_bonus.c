/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 21:14:36 by apanikov          #+#    #+#             */
/*   Updated: 2023/06/15 21:14:37 by apanikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
}

void	swap_b(t_node **b)
{
	if (!*b)
		return ;
	if ((*b)->next == NULL)
		return ;
	swap(b);
}

void	swap_ss(t_node **a, t_node **b)
{
	if (!*b || !*a)
		return ;
	if ((*b)->next == NULL || (*a)->next == NULL)
		return ;
	swap(a);
	swap(b);
}
