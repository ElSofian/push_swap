/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 18:33:22 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/11 13:56:02 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

int	do_commands(char *line, t_pile **a, t_pile **b)
{
	if (!(ft_strcmp(line, "sa")))
		return (swap(a));
	if (!(ft_strcmp(line, "sb")))
		return (swap(b));
	if (!(ft_strcmp(line, "ss")))
		return (swap(a), swap(b));
	if (!(ft_strcmp(line, "pa")))
		return (push(a, b));
	if (!(ft_strcmp(line, "pb")))
		return (push(b, a));
	if (!(ft_strcmp(line, "ra")))
		return (rotate(a));
	if (!(ft_strcmp(line, "rb")))
		return (rotate(b));
	if (!(ft_strcmp(line, "rr")))
		return (rotate(a), rotate(b));
	if (!(ft_strcmp(line, "rra")))
		return (reverse_rotate(a));
	if (!(ft_strcmp(line, "rrb")))
		return (reverse_rotate(b));
	if (!(ft_strcmp(line, "rrr")))
		return (reverse_rotate(a), reverse_rotate(b));
	return (1);
}

void	print_checker_res(t_pile **a, t_pile **b)
{
	if (check_already_sorted(a))
		ft_putendl_fd("OK\n", 1);
	else
		ft_putendl_fd("KO\n", 1);
	if (*a)
		free_stack(a);
	if (*b)
		free_stack(b);
}

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

int	main(int argc, char **argv)
{
	t_pile	**a;
	t_pile	**b;
	char	*line;

	if (argc < 2)
		return (0);
	a = (t_pile **)malloc(sizeof(t_pile));
	b = (t_pile **)malloc(sizeof(t_pile));
	*a = NULL;
	*b = NULL;
	check_args(argc, argv);
	initialize(a, argc, argv);
	line = get_next_line(0);
	while (line)
	{
		if (do_commands(line, a, b))
		{
			exit(EXIT_FAILURE);
			return (-1);
		}
		free(line);
	}
	print_checker_res(a, b);
	return (0);
}
