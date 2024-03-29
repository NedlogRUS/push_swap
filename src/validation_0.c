/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 02:08:32 by apanikov          #+#    #+#             */
/*   Updated: 2023/06/15 02:08:35 by apanikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	counter_arind(char **strar)
{
	int	i;

	i = 0;
	while (strar[i])
		i++;
	return (i);
}

int	*sort_arind(int *arind, int i)
{
	int	j;
	int	buf;

	j = -1;
	while (j < i)
	{
		j++;
		if ((j + 1) < i && arind[j] > arind[j + 1])
		{
			buf = arind[j];
			arind[j] = arind[j + 1];
			arind[j + 1] = buf;
			j = -1;
		}
	}
	return (arind);
}

void	ind_from_arind_to_a(t_node *a, int *arind)
{
	t_node	*tmp;
	int		j;
	int		x;

	tmp = a;
	j = 0;
	x = 0;
	while (tmp != NULL)
	{
		if (tmp->ind == -1)
		{
			while (arind[j] != tmp->num)
				j++;
			tmp->ind = j;
			j = 0;
			tmp = a;
			x = 1;
		}
		if (x == 0)
			tmp = tmp->next;
		else
			x = 0;
	}
}

int	check_empty(char *strar)
{
	int	i;

	i = 0;
	while (strar[i] && strar[i] == ' ')
		i++;
	if (strar[i] == '\0')
		return (1);
	return (0);
}
