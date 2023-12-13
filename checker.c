/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 18:33:22 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/13 12:20:53 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

static int	do_commands(char *line, t_pile **a, t_pile **b)
{
	if (!(ft_strcmp(line, "sa\n")))
		return (swap(a));
	if (!(ft_strcmp(line, "sb\n")))
		return (swap(b));
	if (!(ft_strcmp(line, "ss\n")))
		return (swap(a), swap(b));
	if (!(ft_strcmp(line, "pa\n")))
		return (push(a, b));
	if (!(ft_strcmp(line, "pb\n")))
		return (push(b, a));
	if (!(ft_strcmp(line, "ra\n")))
		return (rotate(a));
	if (!(ft_strcmp(line, "rb\n")))
		return (rotate(b));
	if (!(ft_strcmp(line, "rr\n")))
		return (rotate(a), rotate(b));
	if (!(ft_strcmp(line, "rra\n")))
		return (reverse_rotate(a));
	if (!(ft_strcmp(line, "rrb\n")))
		return (reverse_rotate(b));
	if (!(ft_strcmp(line, "rrr\n")))
		return (reverse_rotate(a), reverse_rotate(b));
	return (-1);
}

static int	check_result(t_pile **a, t_pile **b)
{
	if (check_already_sorted(a))
		ft_putendl_fd("OK\n", 1);
	else
		ft_putendl_fd("KO\n", 1);
	free_stack(a);
	free_stack(b);
	return (0);
}

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

int	main(int ac, char **av)
{
	t_pile	**a;
	t_pile	**b;
	char	*line;

	check_args(ac, av);
	a = (t_pile **)malloc(sizeof(t_pile *));
	b = (t_pile **)malloc(sizeof(t_pile *));
	if (!a || !b)
		error(1);
	*a = NULL;
	*b = NULL;
	initialize(a, av);
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		if (do_commands(line, a, b) == -1)
			return (free_stack(a), free_stack(b), free(line), 0);
		free(line);
		line = NULL;
	}
	free(line);
	return (check_result(a, b));
}
