/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:20:27 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/11 13:20:31 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static t_pile	*get_next_min(t_pile **stack)
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
	t_pile	*head;
	int		index;

	index = 0;
	head = get_next_min(stack);
	while (head)
	{
		head->pos = index++;
		head = get_next_min(stack);
	}
}
