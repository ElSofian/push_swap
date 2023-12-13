/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 18:33:22 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/13 12:15:30 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	error(int ex)
{
	ft_putendl_fd("Error", 2);
	if (ex)
		exit(EXIT_FAILURE);
}

static int	check_contains(int num, int start, char **args)
{
	start++;
	while (args[start])
	{
		if (ft_atoi(args[start]) == num)
			return (1);
		start++;
	}
	return (0);
}

static int	check_num(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (1);
		i++;
	}
	return (0);
}

void	check_args(int ac, char **av)
{
	int		i;
	long	tmp;
	char	**args;	

	if (ac != 2 || av[1] == NULL || !av[1][0])
		error(1);
	i = 0;
	args = ft_split(av[1], ' ');
	if (!args || !args[0])
		error(1);
	while (args[i])
	{
		tmp = ft_atoi(args[i]);
		if (check_num(args[i]) || check_contains(tmp, i, args)
			|| tmp < -2147483648 || tmp > 2147483647)
		{
			ft_freetab(args);
			error(1);
		}
		i++;
	}
	ft_freetab(args);
}
