/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:53:24 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/11 10:02:15 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_pile	*get_next_min(t_pile **stack)
{
	t_pile	*head;
	t_pile	*min;
	int		has_min;

	min = NULL;
	has_min = 0;
	head = *stack;
	if (head)
	{
		while (head)
		{
			if ((head->pos == -1) && (!has_min || head->nb < min->nb))
			{
				min = head;
				has_min = 1;
			}
			head = head->next;
		}
	}
	return (min);
}

void	get_pos(t_pile **stack)
{
	int		pos;
	t_pile	*head;

	pos = 0;
	head = get_next_min(stack);
	while (head)
	{
		head->pos = pos++;
		head = get_next_min(stack);
	}
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
