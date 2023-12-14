/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:34:34 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/14 17:23:19 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

static t_pile	*find_highest(t_pile *pile)
{
	int		highest;
	t_pile	*highest_node;

	if (pile == NULL)
		return (NULL);
	highest = INT_MIN;
	while (pile)
	{
		if (pile->nb > highest)
		{
			highest = pile->nb;
			highest_node = pile;
		}
		pile = pile->next;
	}
	return (highest_node);
}

bool	is_sorted(t_pile *pile)
{
	if (pile == NULL)
		return (1);
	while (pile->next)
	{
		if (pile->nb > pile->next->nb)
			return (false);
		pile = pile->next;
	}
	return (true);
}

void	tiny_sort(t_pile **a)
{
	t_pile	*highest_node;

	highest_node = find_highest(*a);
	if (*a == highest_node)
		ra(a, false);
	else if ((*a)->next == highest_node)
		rra(a, false);
	if ((*a)->nb > (*a)->next->nb)
		sa(a, false);
}

void	handle_five(t_pile **a, t_pile **b)
{
	while (pile_len(*a) > 3)
	{
		init_nodes(*a, *b);
		final_rotation(a, find_smallest(*a), 'a');
		pb(b, a, false);
	}
}
