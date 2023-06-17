/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 21:14:08 by apanikov          #+#    #+#             */
/*   Updated: 2023/06/15 21:14:10 by apanikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

long long	ps_lstsize(t_node *lst)
{
	long long	i;
	t_node		*j;

	j = lst;
	i = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	lst = j;
	return (i);
}

void	rrotate(t_node **s)
{
	t_node		*tmp;
	t_node		*tmp1;
	long long	i;

	i = ps_lstsize(*s);
	tmp = *s;
	while ((*s)->next)
		*s = (*s)->next;
	tmp1 = *s;
	tmp1->next = tmp;
	*s = tmp1;
	while (i > 1)
	{
		*s = (*s)->next;
		i--;
	}
	(*s)->next = NULL;
	*s = tmp1;
}

void	rrotate_a(t_node **a)
{
	if (!*a)
		return ;
	if ((*a)->next == NULL)
		return ;
	rrotate(a);
}

void	rrotate_b(t_node **b)
{
	if (!*b)
		return ;
	if ((*b)->next == NULL)
		return ;
	rrotate(b);
}

void	rrotate_rrr(t_node **a, t_node **b)
{
	if (!*a)
		return ;
	if ((*a)->next == NULL)
		return ;
	if (!*b)
		return ;
	if ((*b)->next == NULL)
		return ;
	rrotate(a);
	rrotate(b);
}
