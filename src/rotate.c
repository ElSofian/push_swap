/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 09:27:06 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/11 10:45:00 by soelalou         ###   ########.fr       */
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

int	ra(t_pile **stack_a)
{
	if (rotate(stack_a) == -1)
		return (-1);
	ft_printf("ra\n");
	return (0);
}

int	rb(t_pile **stack_b)
{
	if (rotate(stack_b) == -1)
		return (-1);
	ft_printf("rb\n");
	return (0);
}

int	rr(t_pile **a, t_pile **b)
{
	if ((lstsize(*a) < 2) || (lstsize(*b) < 2))
		return (-1);
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
	return (0);
}
