/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 18:33:22 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/11 13:30:32 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	check_contains(int num, int start, char **argv)
{
	start++;
	while (argv[start])
	{
		if (ft_atoi(argv[start]) == num)
			exit(EXIT_FAILURE);
		start++;
	}
}

static void	check_num(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			exit(EXIT_FAILURE);
		i++;
	}
}

void	check_args(int argc, char **argv)
{
	int		i;
	long	tmp;
	char	**args;	

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		tmp = ft_atoi(args[i]);
		check_num(args[i]);
		check_contains(tmp, i, args);
		if (tmp < -2147483648 || tmp > 2147483647)
			exit(EXIT_FAILURE);
		i++;
	}
	if (argc == 2)
		ft_freetab(args);
}
