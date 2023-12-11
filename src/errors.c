/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:29:44 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/11 10:44:39 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	error(char *str)
{
	if (str)
		ft_printf("%s\n", str);
	else
		ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

void	check(int ac, char **av)
{
	int		i;
	long	tmp;
	char	**args;	

	i = 0;
	if (ac == 2)
		args = ft_split(av[1], ' ');
	else
	{
		i = 1;
		args = av;
	}
	while (args[i])
	{
		tmp = ft_atoi(args[i]);
		check_int_arg(args[i]);
		check_contain(tmp, i, args);
		if (tmp < -2147483648 || tmp > 2147483647)
			error("Error\n");
		i++;
	}
	if (ac == 2)
		ft_freetab(args);
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
		error(NULL);
}

void	check_int_arg(char *str)
{
	int		i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			error(NULL);
		i++;
	}
}
