/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:07:08 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/11 09:59:37 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	swap(t_pile **stack)
{
	int		tmp_nb;
	int		tmp_pos;
	t_pile	*head;
	t_pile	*next;

	if (lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	next = head->next;
	if (!head && !next)
		error("Error occured while swapping.");
	tmp_nb = head->nb;
	tmp_pos = head->pos;
	head->nb = next->nb;
	head->pos = next->pos;
	next->nb = tmp_nb;
	next->pos = tmp_pos;
	return (0);
}

int	sa(t_pile **a)
{
	if (swap(a) == -1)
		return (-1);
	ft_printf("sa\n");
	return (0);
}

int	sb(t_pile **b)
{
	if (swap(b) == -1)
		return (-1);
	ft_printf("sb\n");
	return (0);
}

int	ss(t_pile **a, t_pile **b)
{
	if ((lstsize(*a) < 2) || (lstsize(*b) < 2))
		return (-1);
	swap(a);
	swap(b);
	ft_printf("ss\n");
	return (0);
}
