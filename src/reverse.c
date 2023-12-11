/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:45:51 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/11 13:35:25 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	reverse_rotate(t_pile **stack)
{
	t_pile	*head;
	t_pile	*tail;

	if (lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	tail = lstlast(head);
	while (head)
	{
		if (head->next->next == NULL)
		{
			head->next = NULL;
			break ;
		}
		head = head->next;
	}
	tail->next = *stack;
	*stack = tail;
	return (0);
}

int	rra(t_pile **a)
{
	if (reverse_rotate(a) == -1)
		return (-1);
	ft_putendl_fd("rra", 1);
	return (0);
}

int	rrb(t_pile **b)
{
	if (reverse_rotate(b) == -1)
		return (-1);
	ft_putendl_fd("rrb", 1);
	return (0);
}

int	rrr(t_pile **a, t_pile **b)
{
	if ((lstsize(*a) < 2) || (lstsize(*b) < 2))
		return (-1);
	reverse_rotate(a);
	reverse_rotate(b);
	ft_putendl_fd("rrr", 1);
	return (0);
}
