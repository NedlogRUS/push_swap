/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 21:14:46 by apanikov          #+#    #+#             */
/*   Updated: 2023/06/15 21:14:48 by apanikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	*ps_strjoin(char *s1, char const *s2)
{
	char	*res;
	int		a;
	int		b;

	a = 0;
	b = 0;
	if (!s1 || !s2)
		return ((char *)malloc(sizeof(char)));
	res = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 2) * sizeof(char));
	if (!res)
		return ((void *)0);
	while (s1[a])
	{
		res[a] = s1[a];
		a++;
	}
	res[a++] = ' ';
	while (s2[b])
		res[a++] = s2[b++];
	free (s1);
	res[a] = '\0';
	return (res);
}

int	ps_atoi(const char *str)
{
	long long	out;
	int			sign;
	int			i;

	out = 0;
	sign = 1;
	i = 0;
	while (str[i] == 32 || (str[i] > 8 && str[i] < 14))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		out = out * 10 + str[i] - '0';
		i++;
		if (!(out * sign >= -2147483648 && out * sign <= 2147483647))
			error_out();
	}
	return ((int)out * sign);
}

t_node	*ps_lstnew(int num)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (0);
	new->num = num;
	new->ind = -1;
	new->next = NULL;
	return (new);
}

void	ps_lstadd_back(t_node **lst, t_node *new)
{
	if (*lst)
		ps_lstlast(*lst)->next = new;
	else
		*lst = new;
}

t_node	*ps_lstlast(t_node *lst)
{
	t_node	*j;

	j = lst;
	if (!j)
		return (0);
	while (j->next != 0)
		j = j->next;
	return (j);
}
