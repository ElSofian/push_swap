/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 18:33:22 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/13 11:58:38 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_pile
{
	int				nb;
	int				pos;
	struct s_pile	*next;
}				t_pile;

// Util functions
int		lstsize(t_pile *head);
void	lstadd_back(t_pile **stack, t_pile *new_lst);
t_pile	*lstnew(int value);
t_pile	*lstlast(t_pile *head);

void	error(int ex);
int		get_min(t_pile **stack, int val);
int		check_already_sorted(t_pile **stack);
int		get_distance(t_pile **stack, int index);
void	check_args(int ac, char **av);
void	make_top(t_pile **stack, int distance);
void	free_stack(t_pile **stack);

// Algorithm utils
void	complex_sort(t_pile **a, t_pile **b);
void	simple_sort(t_pile **a, t_pile **b);
void	get_pos(t_pile **stack);
void	sort_5(t_pile **a, t_pile **b);
void	handler_3(t_pile **a, t_pile *head, int min, int next_min);

// Instruction functions
int		swap(t_pile **stack);
int		push(t_pile **stack_to, t_pile **stack_from);
int		rotate(t_pile **stack);
int		reverse_rotate(t_pile **stack);

int		sa(t_pile **a);
int		sb(t_pile **b);
int		ss(t_pile **a, t_pile **b);
int		pa(t_pile **a, t_pile **b);
int		pb(t_pile **b, t_pile **a);
int		ra(t_pile **a);
int		rb(t_pile **b);
int		rr(t_pile **a, t_pile **b);
int		rra(t_pile **a);
int		rrb(t_pile **b);
int		rrr(t_pile **a, t_pile **b);

#endif