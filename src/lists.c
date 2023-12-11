/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 09:58:11 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/11 10:35:49 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	freepile(t_pile **lst)
{
	t_pile	*tmp;

	if (lst)
	{
		while (*lst)
		{
			tmp = (*lst)->next;
			free(*lst);
			(*lst) = tmp;
		}
	}
	*lst = NULL;
}

void	lstadd_back(t_pile **lst, t_pile *new)
{
	t_pile	*tmp;

	if (!lst || !new)
	{
		if (!lst)
			ft_printf("Argument lst is NULL in ft_lstadd_back() function.\n");
		if (!new)
			ft_printf("Argument new is NULL in ft_lstadd_back() function.\n");
		return ;
	}
	tmp = lstlast(*lst);
	if (!tmp)
		*lst = new;
	else
		tmp->next = new;
}

int	lstsize(t_pile *lst)
{
	int		i;
	t_pile	*tmp;

	tmp = lst;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

t_pile	*lstnew(int nb)
{
	t_pile	*list;

	list = (t_pile *)malloc(sizeof(t_pile));
	if (!list)
	{
		ft_printf("Argument lst is NULL in lstnew() function.\n");
		return (NULL);
	}
	list->nb = nb;
	list->next = NULL;
	return (list);
}

t_pile	*lstlast(t_pile *lst)
{
	t_pile	*tmp;

	tmp = lst;
	while (tmp && tmp->next)
		tmp = tmp->next;
	return (tmp);
}
