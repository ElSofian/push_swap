/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 08:26:10 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/14 11:12:14 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

/*
 * Set the current position of every node 
 * in the current state-configuration
*/
void	set_pos(t_pile *pile)
{
	int	i;
	int	centerline;

	i = 0;
	if (!pile)
		return ;
	centerline = pile_len(pile) / 2;
	while (pile)
	{
		pile->pos = i;
		if (i <= centerline)
			pile->higher_than_median = true;
		else
			pile->higher_than_median = false;
		pile = pile->next;
		++i;
	}
}

/*
 *	Best match is..
 *   | "The Smallest-bigger value" |
 *
 *  if no node is Bigger, best_match is the Smallest node.
 *  TLDR 
 *  With this function every node in b gets its target node in a
*/
static void	set_current(t_pile *a, t_pile *b)
{
	long	best_match_index;
	t_pile	*current_a;
	t_pile	*current;

	while (b)
	{
		best_match_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->value > b->value
				&& current_a->value < best_match_index)
			{
				best_match_index = current_a->value;
				current = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == LONG_MAX)
			b->current = find_smallest(a);
		else
			b->current = current;
		b = b->next;
	}
}

/*
 * Set the prices to push the node
 * from b -> a
 * The price checks for the relative positions in the stack
 * for every node, setting the respective price
*/
void	set_price(t_pile *a, t_pile *b)
{
	int	len_a;
	int	len_b;

	len_a = pile_len(a);
	len_b = pile_len(b);
	while (b)
	{
		b->push_price = b->pos;
		if (!(b->higher_than_median))
			b->push_price = len_b - (b->pos);
		if (b->current->higher_than_median)
			b->push_price += b->current->pos;
		else
			b->push_price += len_a - (b->current->pos);
		b = b->next;
	}
}

/*
 * Flag the lower node in the current
 * stacks configurations
*/
void	set_lower(t_pile *b)
{
	long	best_match_value;
	t_pile	*best_match_node;

	if (!b)
		return ;
	best_match_value = LONG_MAX;
	while (b)
	{
		if (b->push_price < best_match_value)
		{
			best_match_value = b->push_price;
			best_match_node = b;
		}
		b = b->next;
	}
	best_match_node->lower = true;
}

/*
 * All the necessary values to make the push
 * 		~Relative Positions
 * 		~Target node, the b node to make emerge
 * 		~Price for every configuration
 * 		~lower in the current configuration
*/
void	init_nodes(t_pile *a, t_pile *b)
{
	set_pos(a);
	set_pos(b);
	set_current(a, b);
	set_price(a, b);
	set_lower(b);
}
