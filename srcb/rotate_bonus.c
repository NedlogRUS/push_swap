/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 21:12:40 by apanikov          #+#    #+#             */
/*   Updated: 2023/06/15 21:12:42 by apanikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rotate(t_node **s)
{
	t_node	*tmp;
	t_node	*tmp1;

	tmp = *s;
	tmp1 = (*s)->next;
	while ((*s)->next)
		*s = (*s)->next;
	(*s)->next = tmp;
	tmp->next = NULL;
	*s = tmp1;
}

void	rotate_a(t_node **a)
{
	if (!*a)
		return ;
	else if ((*a)->next == NULL)
		return ;
	rotate(a);
}

void	rotate_b(t_node **b)
{
	if (!*b)
		return ;
	else if ((*b)->next == NULL)
		return ;
	rotate(b);
}

void	rotate_rr(t_node **a, t_node **b)
{
	if (!*a)
		return ;
	else if ((*a)->next == NULL)
		return ;
	if (!*b)
		return ;
	else if ((*b)->next == NULL)
		return ;
	rotate(a);
	rotate(b);
}
