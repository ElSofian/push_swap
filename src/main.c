/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 18:33:22 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/13 11:58:49 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	initialize(t_pile **stack, char **av)
{
	t_pile	*new;
	char	**args;
	int		i;

	i = 0;
	args = ft_split(av[1], ' ');
	while (args[i])
	{
		new = lstnew(ft_atoi(args[i]));
		lstadd_back(stack, new);
		i++;
	}
	get_pos(stack);
	ft_freetab(args);
}

static void	sort(t_pile **a, t_pile **b)
{
	if (lstsize(*a) <= 5)
		simple_sort(a, b);
	else
		complex_sort(a, b);
}

int	main(int ac, char **av)
{
	t_pile	**a;
	t_pile	**b;

	check_args(ac, av);
	a = (t_pile **)malloc(sizeof(t_pile *));
	b = (t_pile **)malloc(sizeof(t_pile *));
	*a = NULL;
	*b = NULL;
	initialize(a, av);
	if (check_already_sorted(a))
	{
		free_stack(a);
		free_stack(b);
		return (0);
	}
	sort(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}
