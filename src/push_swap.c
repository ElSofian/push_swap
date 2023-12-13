/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 07:27:28 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/13 21:09:32 by soelalou         ###   ########.fr       */
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
	while (*a != lower_node->current
		&& *b != lower_node)
		rr(a, b, false);
	set_pos(*a);
	set_pos(*b);
}

static void	reverse_rotate_both(t_pile **a, t_pile **b, t_pile *lower_node)
{
	while (*a != lower_node->current
		&& *b != lower_node)
		rrr(a, b, false);
	set_pos(*a);
	set_pos(*b);
}

/*
 * Conclude the rotation of the stacks 
*/
void	final_rotation(t_pile **stack, t_pile *top_node, char pile)
{
	while (*stack != top_node)
	{
		if (pile == 'a')
		{
			if (top_node->higher_than_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (pile == 'b')
		{
			if (top_node->higher_than_median)
				rb(stack, false);
			else
				rrb(stack, false);
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
		&& lower_node->current->higher_than_median)
		rotate_both(a, b, lower_node);
	else if (!(lower_node->higher_than_median)
		&& !(lower_node->current->higher_than_median))
		reverse_rotate_both(a, b, lower_node);
	final_rotation(b, lower_node, 'b');
	final_rotation(a, lower_node->current, 'a');
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
