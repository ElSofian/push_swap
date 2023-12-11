/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 18:33:22 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/11 13:30:32 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	initialize(t_pile **stack, int argc, char **argv)
{
	t_pile	*new;
	char	**args;
	int		i;

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
		new = lstnew(ft_atoi(args[i]));
		lstadd_back(stack, new);
		i++;
	}
	get_pos(stack);
	if (argc == 2)
		ft_freetab(args);
}

static void	sort(t_pile **a, t_pile **b)
{
	if (lstsize(*a) <= 5)
		simple_sort(a, b);
	else
		complex_sort(a, b);
}

int	main(int argc, char **argv)
{
	t_pile	**a;
	t_pile	**b;

	if (argc < 2)
		return (-1);
	check_args(argc, argv);
	a = (t_pile **)malloc(sizeof(t_pile));
	b = (t_pile **)malloc(sizeof(t_pile));
	*a = NULL;
	*b = NULL;
	initialize(a, argc, argv);
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
