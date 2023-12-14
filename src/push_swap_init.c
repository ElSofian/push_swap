/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 08:26:10 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/14 17:25:00 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

static void	set_target(t_pile *a, t_pile *b)
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
			if (current_a->nb > b->nb
				&& current_a->nb < best_match_index)
			{
				best_match_index = current_a->nb;
				current = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == LONG_MAX)
			b->target = find_smallest(a);
		else
			b->target = current;
		b = b->next;
	}
}

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

void	set_moves_count(t_pile *a, t_pile *b)
{
	int	len_a;
	int	len_b;

	len_a = pile_len(a);
	len_b = pile_len(b);
	while (b)
	{
		b->moves_count = b->pos;
		if (!(b->higher_than_median))
			b->moves_count = len_b - (b->pos);
		if (b->target->higher_than_median)
			b->moves_count += b->target->pos;
		else
			b->moves_count += len_a - (b->target->pos);
		b = b->next;
	}
}

void	set_lower(t_pile *b)
{
	long	best_match_value;
	t_pile	*best_match_node;

	if (!b)
		return ;
	best_match_value = LONG_MAX;
	while (b)
	{
		if (b->moves_count < best_match_value)
		{
			best_match_value = b->moves_count;
			best_match_node = b;
		}
		b = b->next;
	}
	best_match_node->lowest = true;
}

void	init_nodes(t_pile *a, t_pile *b)
{
	set_pos(a);
	set_pos(b);
	set_target(a, b);
	set_moves_count(a, b);
	set_lower(b);
}
