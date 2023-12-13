/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 18:33:22 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/13 12:44:05 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	handler_3(t_pile **a, t_pile *head, int min, int next_min)
{
	if (head->pos == min && head->next->pos != next_min)
	{
		ra(a);
		sa(a);
		rra(a);
	}
	else if (head->pos == next_min)
	{
		if (head->next->pos == min)
			sa(a);
		else
			rra(a);
	}
	else
	{
		if (head->next->pos == min)
			ra(a);
		else
		{
			sa(a);
			rra(a);
		}
	}
}

static void	sort_3(t_pile **a)
{
	t_pile	*head;
	int		min;
	int		next_min;

	head = *a;
	min = get_min(a, -1);
	next_min = get_min(a, min);
	if (check_already_sorted(a))
		return ;
	handler_3(a, head, min, next_min);
}

static void	sort_4(t_pile **a, t_pile **b)
{
	int	distance;

	if (check_already_sorted(a))
		return ;
	distance = get_distance(a, get_min(a, -1));
	if (distance == 1)
		ra(a);
	else if (distance == 2)
	{
		ra(a);
		ra(a);
	}
	else if (distance == 3)
		rra(a);
	if (check_already_sorted(a))
		return ;
	pb(a, b);
	sort_3(a);
	pa(a, b);
}

static void	sort_5(t_pile **a, t_pile **b)
{
	int	distance;

	distance = get_distance(a, get_min(a, -1));
	if (distance == 1)
		ra(a);
	else if (distance == 2)
	{
		ra(a);
		ra(a);
	}
	else if (distance == 3)
	{
		rra(a);
		rra(a);
	}
	else if (distance == 4)
		rra(a);
	if (check_already_sorted(a))
		return ;
	pb(a, b);
	sort_4(a, b);
	pa(a, b);
}

void	simple_sort(t_pile **a, t_pile **b)
{
	int	size;

	if (check_already_sorted(a) || lstsize(*a) == 0
		|| lstsize(*a) == 1)
		return ;
	size = lstsize(*a);
	if (size == 2)
		sa(a);
	else if (size == 3)
		sort_3(a);
	else if (size == 4)
		sort_4(a, b);
	else if (size == 5)
		sort_5(a, b);
}
