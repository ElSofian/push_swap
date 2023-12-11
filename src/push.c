/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 09:25:36 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/11 09:59:37 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	push(t_pile **dst, t_pile **src)
{
	t_pile	*tmp;
	t_pile	*head_dst;
	t_pile	*head_src;

	if (lstsize(*src) == 0)
		return (-1);
	head_dst = *dst;
	head_src = *src;
	tmp = head_src;
	head_src = head_src->next;
	*src = head_src;
	if (!head_dst)
	{
		head_dst = tmp;
		head_dst->next = NULL;
		*dst = head_dst;
	}
	else
	{
		tmp->next = head_dst;
		*dst = tmp;
	}
	return (0);
}

int	pa(t_pile **a, t_pile **b)
{
	if (push(a, b) == -1)
		return (-1);
	ft_printf("pa\n");
	return (0);
}

int	pb(t_pile **a, t_pile **b)
{
	if (push(b, a) == -1)
		return (-1);
	ft_printf("pb\n");
	return (0);
}
