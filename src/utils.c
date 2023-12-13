/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 18:33:22 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/13 12:44:43 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	check_already_sorted(t_pile **stack)
{
	t_pile	*head;

	head = *stack;
	while (head && head->next)
	{
		if (head->nb > head->next->nb)
			return (0);
		head = head->next;
	}
	return (1);
}

int	get_distance(t_pile **stack, int index)
{
	t_pile	*head;
	int		distance;

	distance = 0;
	head = *stack;
	while (head)
	{
		if (head->pos == index)
			break ;
		distance++;
		head = head->next;
	}
	return (distance);
}

int	get_min(t_pile **stack, int val)
{
	t_pile	*head;
	int		min;

	head = *stack;
	min = head->pos;
	while (head->next)
	{
		head = head->next;
		if ((head->pos < min) && head->pos != val)
			min = head->pos;
	}
	return (min);
}

void	make_top(t_pile **stack, int distance)
{
	t_pile	*head;
	int		tmp;

	if (distance == 0)
		return ;
	head = *stack;
	tmp = lstsize(head) - distance;
	if (distance <= (lstsize(head) / 2))
	{
		while (distance-- > 0)
			ra(stack);
	}
	else
	{
		while (tmp-- > 0)
			rra(stack);
	}
}

void	free_stack(t_pile **stack)
{
	t_pile	*head;
	t_pile	*tmp;

	head = *stack;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(stack);
}
