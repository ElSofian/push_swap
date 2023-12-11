/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:08:02 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/11 13:40:26 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	swap(t_pile **stack)
{
	t_pile	*head;
	t_pile	*next;
	int		tmp_val;
	int		tmp_index;

	if (lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	next = head->next;
	if (!head && !next)
		exit(EXIT_FAILURE);
	tmp_val = head->nb;
	tmp_index = head->pos;
	head->nb = next->nb;
	head->pos = next->pos;
	next->nb = tmp_val;
	next->pos = tmp_index;
	return (0);
}

int	sa(t_pile **a)
{
	if (swap(a) == -1)
		return (-1);
	ft_putendl_fd("sa", 1);
	return (0);
}

int	sb(t_pile **b)
{
	if (swap(b) == -1)
		return (-1);
	ft_putendl_fd("sb", 1);
	return (0);
}

int	ss(t_pile **a, t_pile **b)
{
	if ((lstsize(*a) < 2) || (lstsize(*b) < 2))
		return (-1);
	swap(a);
	swap(b);
	ft_putendl_fd("ss", 1);
	return (0);
}
