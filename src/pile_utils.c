/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 20:26:39 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/13 21:09:47 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <limits.h>

t_pile	*find_last_node(t_pile *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

/*
 * Search for the last node and append 
 * 🚨 Pay attention if the stack empty?
*/
void	append_node(t_pile **stack, int nbr)
{
	t_pile	*node;
	t_pile	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_pile));
	if (!node)
		return ;
	node->next = NULL;
	node->value = nbr;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

/*
 * Find the smallest value node
*/
t_pile	*find_smallest(t_pile *pile)
{
	long	smallest;
	t_pile	*smallest_node;

	if (!pile)
		return (NULL);
	smallest = LONG_MAX;
	while (pile)
	{
		if (pile->value < smallest)
		{
			smallest = pile->value;
			smallest_node = pile;
		}
		pile = pile->next;
	}
	return (smallest_node);
}

/*
 * Return the lower node 
 * that is already flagged
*/
t_pile	*return_lower(t_pile *pile)
{
	if (!pile)
		return (NULL);
	while (pile)
	{
		if (pile->lower)
			return (pile);
		pile = pile->next;
	}
	return (NULL);
}

int	pile_len(t_pile *pile)
{
	int	count;

	if (!pile)
		return (0);
	count = 0;
	while (pile)
	{
		++count;
		pile = pile->next;
	}
	return (count);
}
