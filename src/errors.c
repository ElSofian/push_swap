/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 20:25:58 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/14 17:19:53 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdlib.h>
#include <stdio.h>

void	ft_free_av(char **av)
{
	int	i;

	i = -1;
	if (!av || !(*av))
		return ;
	while (av[i])
		free(av[i++]);
	free(av - 1);
}

void	free_pile(t_pile **pile)
{
	t_pile	*tmp;
	t_pile	*current;

	if (!pile)
		return ;
	current = *pile;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*pile = NULL;
}

void	error(t_pile **a, char **av, bool is_string)
{
	free_pile(a);
	if (is_string)
		ft_free_av(av);
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

int	check_format(char *str_nbr)
{
	if (!(*str_nbr == '+'
			|| *str_nbr == '-'
			|| (*str_nbr >= '0' && *str_nbr <= '9')))
		return (1);
	if ((*str_nbr == '+'
			|| *str_nbr == '-')
		&& !(str_nbr[1] >= '0' && str_nbr[1] <= '9'))
		return (1);
	while (*++str_nbr)
	{
		if (!(*str_nbr >= '0' && *str_nbr <= '9'))
			return (1);
	}
	return (0);
}

int	check_doubles(t_pile *a, int nbr)
{
	if (NULL == a)
		return (0);
	while (a)
	{
		if (a->nb == nbr)
			return (1);
		a = a->next;
	}
	return (0);
}
