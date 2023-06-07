# include "push_swap.h"

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

// int	ps_atoi(const char *str)
// {
// 	long	out;
// 	int		sign;
// 	int		i;

// 	out = 0;
// 	sign = 1;
// 	i = 0;
// 	while (str[i] == 32 || (str[i] > 8 && str[i] < 14))
// 		i++;
// 	if (str[i] == '-' || str[i] == '+')
// 	{
// 		if (str[i] == '-')
// 			sign *= -1;
// 		i++;
// 	}
// 	while (str[i] >= '0' && str[i] <= '9')
// 	{
// 		out = out * 10 + str[i] - '0';
// 		i++;
// 		if (!(out * sign <= -2147483648 && out * sign >= 2147483647))
// 			eror_out();
// 	}
// 	return ((int)out * sign);
// }

void eror_out(void)
{
	ft_putstr_fd("Eror\n", 2);
	exit (1);
}

// void check_input(char *str)
// {
// 	int i;

// 	i = 0;
// 	while(str[i++])
// 		if(!ft_isascii(str[i]))
// 			eror_out();
// }

void ps_check(char *str)
{
	char **strm;
	int i = 0;
	strm = ft_split(str, ' ');
	while (strm[i])
		printf("%s\n", strm[i++]);
	check_number
}

int main (int ac, char **av)
{
	// t_node a;
	// t_node b;
	char *str;

	if (ac <= 1)
		exit (1);
	ac = 1;
	str = ft_strdup(av[ac++]);
	while (av[ac])
	{
		str = ps_strjoin(str, av[ac]);
		// printf("%s\n", av[ac]);
		ac++;
	}
	ps_check(str);
	printf("%s\n", str);
	// system("leaks push_swap");
	exit (0);
}