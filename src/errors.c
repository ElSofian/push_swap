/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 20:25:58 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/14 13:49:32 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdlib.h>
#include <stdio.h>

/*
 * Ad hoc function to free the 2D array
 * created with the ft_split function
 * ATTENTION
 * You have to start from -1 
*/
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

/*
 * Ad hoc function to free a pile
*/
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

/*
 * Matrix starts from -1
 * because i artificially made Up
 * equal to av
*/
void	error(t_pile **a, char **av, bool is_string)
{
	free_pile(a);
	if (is_string)
		ft_free_av(av);
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

/*
 * Check if there are some syntactical mistakes
*/
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

/*
 * Loop into the pile for some repetition
*/
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
