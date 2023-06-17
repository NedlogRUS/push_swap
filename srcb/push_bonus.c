/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 21:12:29 by apanikov          #+#    #+#             */
/*   Updated: 2023/06/15 21:12:30 by apanikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	push(t_node **f, t_node **s)
{
	t_node	*tmp;
	t_node	*tmp1;

	tmp = *f;
	tmp1 = *s;
	*f = (*f)->next;
	tmp->next = tmp1;
	*s = tmp;
}

void	push_a(t_node **a, t_node **b)
{
	if (!*b)
		return ;
	push(b, a);
}

void	push_b(t_node **a, t_node **b)
{
	if (!*a)
		return ;
	push(a, b);
}
