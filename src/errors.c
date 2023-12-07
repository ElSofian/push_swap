/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:29:44 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/07 13:55:52 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	error(void)
{
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

void	check(t_pile *a, t_pile *b, char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		check_int_arg(av[i]);
		check_int(av[i]);
		i++;
	}
	check_doubles(a);
	check_result(&a, &b);
}

void	check_int(char *str)
{
	long long int	nb;
	int				sign;

	nb = 0;
	sign = 1;
	while (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f'
		|| *str == '\r' || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1;
	while (*str >= '0' && *str <= '9')
		nb = nb * 10 + (*str++ - '0');
	if (*str != '\0' || nb > 2147483647 || nb < -2147483648)
		error();
}

void	check_int_arg(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' && str[i + 1] == ' ')
			error();
		if (str[i] == '-' && str[i + 1] == ' ')
			error();
		if (str[i] == '+' && str[i + 1] == ' ')
			error();
		if (str[i] == ' ' && str[i + 1] == '-')
			error();
		if (str[i] == ' ' && str[i + 1] == '+')
			error();
		if (str[i] == '-' && str[i + 1] == '-')
			error();
		if (str[i] == '+' && str[i + 1] == '+')
			error();
		i++;
	}
}

void	check_doubles(t_pile *a)
{
	t_pile	*tmp;
	t_pile	*tmp2;

	tmp = (t_pile *)malloc(sizeof(t_pile));
	tmp2 = (t_pile *)malloc(sizeof(t_pile));
	tmp = a;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp->nb == tmp2->nb)
				error();
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	freepile(&tmp);
	freepile(&tmp2);
}

void	check_result(t_pile **a, t_pile **b)
{
	t_pile	*tmp;

	tmp = (t_pile *)malloc(sizeof(t_pile));
	tmp = *a;
	while (tmp->next)
	{
		if (tmp->nb > tmp->next->nb)
		{
			freepile(a);
			freepile(b);
			error();
		}
		tmp = tmp->next;
	}
	tmp = *b;
	if (tmp)
	{
		freepile(a);
		freepile(b);
		error();
	}
}