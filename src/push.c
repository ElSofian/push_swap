/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:53:10 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/13 21:09:34 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
 * Push a node to the top from src to dest
 * 🚨 attention If stack empty (i.e. NULL)
*/
static void	push(t_pile **dest, t_pile **src)
{
	t_pile	*node_to_push;

	if (!(*src))
		return ;
	node_to_push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	node_to_push->prev = NULL;
	if (NULL == *dest)
	{
		*dest = node_to_push;
		node_to_push->next = NULL;
	}
	else
	{
		node_to_push->next = *dest;
		node_to_push->next->prev = node_to_push;
		*dest = node_to_push;
	}
}

void	pa(t_pile **a, t_pile **b, bool checker)
{
	push(a, b);
	if (!checker)
		ft_printf("pa\n");
}

void	pb(t_pile **b, t_pile **a, bool checker)
{
	push(b, a);
	if (!checker)
		ft_printf("pb\n");
}
