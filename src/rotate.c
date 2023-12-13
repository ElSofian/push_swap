/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:59:30 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/13 21:09:44 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
 * Top node to bottom position
*/
static void	rotate(t_pile **pile)
{
	int		len;
	t_pile	*last_node;

	len = pile_len(*pile);
	if (!pile || !(*pile) || len == 1)
		return ;
	last_node = find_last_node(*pile);
	last_node->next = *pile;
	*pile = (*pile)->next;
	(*pile)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ra(t_pile **a, bool checker)
{
	rotate(a);
	if (!checker)
		ft_printf("ra\n");
}

void	rb(t_pile **b, bool checker)
{
	rotate(b);
	if (!checker)
		ft_printf("rb\n");
}

void	rr(t_pile **a, t_pile **b, bool checker)
{
	rotate(a);
	rotate(b);
	if (!checker)
		ft_printf("rr\n");
}
