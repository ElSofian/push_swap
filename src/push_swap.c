/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 07:27:28 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/14 16:51:53 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * Loop decays once
 * 		~lower_node tops is a
 * 		~relative current tops in b
*/
static void	rotate_both(t_pile **a, t_pile **b, t_pile *lower_node)
{
	while (*a != lower_node->target
		&& *b != lower_node)
		rr(a, b, false);
	set_pos(*a);
	set_pos(*b);
}

static void	reverse_rotate_both(t_pile **a, t_pile **b, t_pile *lower_node)
{
	while (*a != lower_node->target
		&& *b != lower_node)
		rrr(a, b, false);
	set_pos(*a);
	set_pos(*b);
}

/*
 * Conclude the rotation of the piles 
*/
void	final_rotation(t_pile **pile, t_pile *top_node, char pile_name)
{
	while (*pile != top_node)
	{
		if (pile_name == 'a')
		{
			if (top_node->higher_than_median)
				ra(pile, false);
			else
				rra(pile, false);
		}
		else if (pile_name == 'b')
		{
			if (top_node->higher_than_median)
				rb(pile, false);
			else
				rrb(pile, false);
		}
	}
}

/*
 * Move the node from 'b' to 'a'
 * with the metadata available in the node
 * 1)Make the target nodes emerge
 * 2)push in A
*/
static void	move_nodes(t_pile **a, t_pile **b)
{
	t_pile	*lower_node;

	lower_node = return_lower(*b);
	if (lower_node->higher_than_median
		&& lower_node->target->higher_than_median)
		rotate_both(a, b, lower_node);
	else if (!(lower_node->higher_than_median)
		&& !(lower_node->target->higher_than_median))
		reverse_rotate_both(a, b, lower_node);
	final_rotation(b, lower_node, 'b');
	final_rotation(a, lower_node->target, 'a');
	pa(a, b, false);
}

/*
 * ~Push all nodes in B 
 * ~For every configuration choose the "lower_node"
 * ~Push everything back in A in order
*/
void	push_swap(t_pile **a, t_pile **b)
{
	int		len_a;
	t_pile	*smallest;

	len_a = pile_len(*a);
	while (len_a-- > 3)
		pb(b, a, false);
	tiny_sort(a);
	while (*b)
	{
		init_nodes(*a, *b);
		move_nodes(a, b);
	}
	set_pos(*a);
	smallest = find_smallest(*a);
	if (smallest->higher_than_median)
		while (*a != smallest)
			ra(a, false);
	else
		while (*a != smallest)
			rra(a, false);
}
