/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:48:25 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/13 21:09:35 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
 * Bottom to top
*/
static void	reverse_rotate(t_pile **pile)
{
	int		len;
	t_pile	*last;

	len = pile_len(*pile);
	if (!pile || !(*pile) || 1 == len)
		return ;
	last = find_last_node(*pile);
	last->prev->next = NULL;
	last->next = *pile;
	last->prev = NULL;
	*pile = last;
	last->next->prev = last;
}

void	rra(t_pile **a, bool checker)
{
	reverse_rotate(a);
	if (!checker)
		write(1, "rra\n", 4);
}

void	rrb(t_pile **b, bool checker)
{
	reverse_rotate(b);
	if (!checker)
		write(1, "rrb\n", 4);
}

void	rrr(t_pile **a, t_pile **b, bool checker)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (!checker)
		write(1, "rrr\n", 4);
}
