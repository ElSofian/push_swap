/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:56:47 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/11 10:46:02 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	check_contain(int nb, int start, char **av)
{
	start++;
	while (av[start])
	{
		if (ft_atoi(av[start]) == nb)
			error(NULL);
		start++;
	}
}

void	check_already_sorted(t_pile **a, t_pile **b)
{
	t_pile	*tmp;

	tmp = *a;
	while (tmp->next)
	{
		if (tmp->nb > tmp->next->nb)
			return ;
		tmp = tmp->next;
	}
	freepile(a);
	freepile(b);
	exit(EXIT_FAILURE);
}
