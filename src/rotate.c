/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:45:15 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/11 13:35:11 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	rotate(t_pile **stack)
{
	t_pile	*head;
	t_pile	*tail;

	if (lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	tail = lstlast(head);
	*stack = head->next;
	head->next = NULL;
	tail->next = head;
	return (0);
}

int	ra(t_pile **a)
{
	if (rotate(a) == -1)
		return (-1);
	ft_putendl_fd("ra", 1);
	return (0);
}

int	rb(t_pile **b)
{
	if (rotate(b) == -1)
		return (-1);
	ft_putendl_fd("rb", 1);
	return (0);
}

int	rr(t_pile **a, t_pile **b)
{
	if ((lstsize(*a) < 2) || (lstsize(*b) < 2))
		return (-1);
	rotate(a);
	rotate(b);
	ft_putendl_fd("rr", 1);
	return (0);
}
