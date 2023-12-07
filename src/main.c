/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:30:28 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/07 14:00:16 by soelalou         ###   ########.fr       */
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
──────────────\n\n");
}

void	initialize(t_pile **a, int ac, char **av)
{
	int		i;
	t_pile	*tmp;

	i = 0;
	tmp = NULL;
	while (++i < ac)
	{
		if (!tmp)
		{
			tmp = (t_pile *)malloc(sizeof(t_pile));
			tmp->nb = ft_atoi(av[i]);
			tmp->pos = i - 1;
			tmp->next = NULL;
			tmp->prev = NULL;
			*a = tmp;
		}
		else
		{
			tmp->next = (t_pile *)malloc(sizeof(t_pile));
			tmp->next->nb = ft_atoi(av[i]);
			tmp->next->pos = i - 1;
			tmp->next->prev = tmp;
			tmp = tmp->next;
		}
	}
}

int	main(int ac, char **av)
{
	t_pile	*a;
	t_pile	*b;
	
	display_banner(RED);
	check(a, b, av);
	return (0);
}
