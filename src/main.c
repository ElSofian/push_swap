/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:26:06 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/14 13:43:22 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
 * Create the pile with the command line values
 * Checks are embedded in the creation itslef
 * 		~Duplicate values
 * 		~Over|Underflow
 * 		~Syntax errors
 *
 * 	🏁 Flag is useful cause if true, i have the av in the HEAP to free
 *
*/
void	initialize(t_pile **a, char **av, bool is_string)
{
	long	nbr;
	int		i;

	i = 0;
	while (av[i])
	{
		if (check_format(av[i]))
			error(a, av, is_string);
		nbr = ft_atoi(av[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			error(a, av, is_string);
		if (check_doubles(*a, (int)nbr))
			error(a, av, is_string);
		append_node(a, (int)nbr);
		++i;
	}
	if (is_string)
		ft_free_av(av);
}

int	main(int ac, char **av)
{
	t_pile	*a;
	t_pile	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2)
		av = split(av[1], ' ');
	initialize(&a, av + 1, ac == 2);
	if (!is_sorted(a))
	{
		if (pile_len(a) == 2)
			sa(&a, false);
		push_swap(&a, &b);
	}
	free_pile(&a);
}
