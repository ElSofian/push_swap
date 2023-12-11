/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:44:59 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/11 09:59:37 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	print_list(t_pile *head)
{
	t_pile	*tmp;

	tmp = head;
	while (tmp != NULL)
	{
		ft_printf("%d\n", tmp->nb);
		tmp = tmp->next;
	}
}

int	is_sorted(t_pile **stack)
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

int	get_distance(t_pile **stack, int pos)
{
	int		distance;
	t_pile	*head;

	distance = 0;
	head = *stack;
	while (head)
	{
		if (head->pos == pos)
			break ;
		distance++;
		head = head->next;
	}
	return (distance);
}

void	make_top(t_pile **stack, int distance)
{
	int		tmp;
	t_pile	*head;

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
