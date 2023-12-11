/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:30:28 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/11 10:31:52 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	display_banner(char *color)
{
	ft_printf("\n\t%s██████╗ ██╗   ██╗███████╗██╗  ██╗        ███████╗██╗    ██╗ █████╗ ██████╗\
	%s", color, RESTART);
	ft_printf("\n\t%s██╔══██╗██║   ██║██╔════╝██║  ██║        ██╔════╝██║    ██║██╔══██╗██╔══██╗\
	%s", color, RESTART);
	ft_printf("\n\t%s██████╔╝██║   ██║███████╗███████║        ███████╗██║ █╗ ██║███████║██████╔╝\
	%s", color, RESTART);
	ft_printf("\n\t%s██╔═══╝ ██║   ██║╚════██║██╔══██║        ╚════██║██║███╗██║██╔══██║██╔═══╝\
	%s", color, RESTART);
	ft_printf("\n\t%s██║     ╚██████╔╝███████║██║  ██║███████╗███████║╚███╔███╔╝██║  ██║██║\
	%s", color, RESTART);
	ft_printf("\n\t%s╚═╝      ╚═════╝ ╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝ ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝%s\
	\n\n", color, RESTART);
	ft_printf("\t────────────────────────────────────────────────────────────\
──────────────\n\n\n");
}

void	sort(t_pile **a, t_pile **b)
{
	if (lstsize(*a) <= 5)
		simple_sort(a, b);
	else
		radix_sort(a, b);
}

void	initialize(t_pile **stack, int argc, char **argv)
{
	int		i;
	char	**args;
	t_pile	*new;

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

int	main(int ac, char **av)
{
	t_pile	**a;
	t_pile	**b;

	check(ac, av);
	a = (t_pile **)malloc(sizeof(t_pile));
	b = (t_pile **)malloc(sizeof(t_pile));
	*a = NULL;
	*b = NULL;
	display_banner(RED);
	initialize(a, ac, av);
	check_already_sorted(a, b);
	sort(a, b);
	freepile(a);
	freepile(b);
	return (0);
}
