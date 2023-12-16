/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 20:27:07 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/16 09:49:18 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

void	error_checker(t_pile **a, t_pile **b)
{
	free_pile(a);
	free_pile(b);
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

static void	parse_cmd(t_pile **a, t_pile **b, char *cmd)
{
	if (!ft_strcmp(cmd, "pa\n"))
		pa(a, b, true);
	else if (!ft_strcmp(cmd, "pb\n"))
		pb(b, a, true);
	else if (!ft_strcmp(cmd, "sa\n"))
		sa(a, true);
	else if (!ft_strcmp(cmd, "sb\n"))
		sb(b, true);
	else if (!ft_strcmp(cmd, "ss\n"))
		ss(a, b, true);
	else if (!ft_strcmp(cmd, "ra\n"))
		ra(a, true);
	else if (!ft_strcmp(cmd, "rb\n"))
		rb(b, true);
	else if (!ft_strcmp(cmd, "rr\n"))
		rr(a, b, true);
	else if (!ft_strcmp(cmd, "rra\n"))
		rra(a, true);
	else if (!ft_strcmp(cmd, "rrb\n"))
		rrb(b, true);
	else if (!ft_strcmp(cmd, "rrr\n"))
		rrr(a, b, true);
	else
		error_checker(a, b);
}

static void	init(t_pile **a, char **av, bool is_string)
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
	int		len;
	char	*line;
	t_pile	*a;
	t_pile	*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	else if (ac == 2)
		av = split(av[1], ' ');
	init(&a, av + 1, ac == 2);
	len = pile_len(a);
	line = get_next_line(0);
	while (line)
	{
		parse_cmd(&a, &b, line);
		line = get_next_line(0);
	}
	if (is_sorted(a) && pile_len(a) == len)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free(a);
	return (0);
}
