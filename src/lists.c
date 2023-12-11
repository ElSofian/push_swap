/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 18:33:22 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/11 13:30:32 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// Creates new node and returns the pointer of it
t_pile	*lstnew(int value)
{
	t_pile	*new;

	new = (t_pile *) malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->nb = value;
	new->pos = -1;
	new->next = NULL;
	return (new);
}

// Returns the last node of a list 
t_pile	*lstlast(t_pile *head)
{
	t_pile	*tmp;

	tmp = head;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->next == NULL)
			return (tmp);
	}
	return (tmp);
}

// Adds the specified node to a stack (list) making it the last node
void	lstadd_back(t_pile **stack, t_pile *new_lst)
{
	t_pile	*tmp;

	if (*stack)
	{
		tmp = lstlast(*stack);
		tmp->next = new_lst;
		new_lst->next = NULL;
	}
	else
	{
		*stack = new_lst;
		(*stack)->next = NULL;
	}
}

// Returns the size of the Linked List
int	lstsize(t_pile *head)
{
	size_t	i;
	t_pile	*tmp;

	tmp = head;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
