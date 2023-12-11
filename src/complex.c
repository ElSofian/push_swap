/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 09:31:03 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/11 10:03:50 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	get_max_bits(t_pile **stack)
{
	t_pile	*head;
	int		max;
	int		max_bits;

	head = *stack;
	max = head->pos;
	max_bits = 0;
	while (head)
	{
		if (head->pos > max)
			max = head->pos;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_pile **a, t_pile **b)
{
	int		i;
	int		j;
	int		size;
	int		max_bits;
	t_pile	*head_a;

	i = 0;
	head_a = *a;
	size = lstsize(head_a);
	max_bits = get_max_bits(a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			head_a = *a;
			if (((head_a->pos >> i) & 1) == 1)
				ra(a);
			else
				pb(a, b);
		}
		while (lstsize(*b) != 0)
			pa(a, b);
		i++;
	}
}
