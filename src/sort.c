/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:34:34 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/13 21:09:46 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

/*
 * Check if a given pile is sorted
*/
bool	is_sorted(t_pile *pile)
{
	if (pile == NULL)
		return (1);
	while (pile->next)
	{
		if (pile->value > pile->next->value)
			return (false);
		pile = pile->next;
	}
	return (true);
}

static t_pile	*find_highest(t_pile *pile)
{
	int		highest;
	t_pile	*highest_node;

	if (pile == NULL)
		return (NULL);
	highest = INT_MIN;
	while (pile)
	{
		if (pile->value > highest)
		{
			highest = pile->value;
			highest_node = pile;
		}
		pile = pile->next;
	}
	return (highest_node);
}

/*
 * When i have 3 nodes, easy to sort
 * 	~If the 1* is the biggest, ra (biggestto bottom)
 * 	~If the 2* is the biggest, rra (biggest to bottom)
 * 	~Now i have forcefully the Biggest at the bottom
 * 		so i just chek 1° and 2°
*/
void	tiny_sort(t_pile **a)
{
	t_pile	*highest_node;

	highest_node = find_highest(*a);
	if (*a == highest_node)
		ra(a, false);
	else if ((*a)->next == highest_node)
		rra(a, false);
	if ((*a)->value > (*a)->next->value)
		sa(a, false);
}

/*
 * Handle input 5
*/
void	handle_five(t_pile **a, t_pile **b)
{
	while (pile_len(*a) > 3)
	{
		init_nodes(*a, *b);
		final_rotation(a, find_smallest(*a), 'a');
		pb(b, a, false);
	}
}
