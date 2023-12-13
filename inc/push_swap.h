/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 18:33:22 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/13 12:44:38 by soelalou         ###   ########.fr       */
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

// Complex
void	complex_sort(t_pile **a, t_pile **b);

// Simple
void	simple_sort(t_pile **a, t_pile **b);

// Errors
void	error(int ex);
void	check_args(int ac, char **av);

// Lists
int		lstsize(t_pile *head);
void	lstadd_back(t_pile **stack, t_pile *new_lst);
t_pile	*lstnew(int value);
t_pile	*lstlast(t_pile *head);

// Position
void	get_pos(t_pile **stack);

// Moves
// 		Push
int		push(t_pile **stack_to, t_pile **stack_from);
int		pa(t_pile **a, t_pile **b);
int		pb(t_pile **b, t_pile **a);

// 		Reverse
int		reverse_rotate(t_pile **stack);
int		rra(t_pile **a);
int		rrb(t_pile **b);
int		rrr(t_pile **a, t_pile **b);

// 		Rotate
int		rotate(t_pile **stack);
int		ra(t_pile **a);
int		rb(t_pile **b);
int		rr(t_pile **a, t_pile **b);

// 		Swap
int		swap(t_pile **stack);
int		sa(t_pile **a);
int		sb(t_pile **b);
int		ss(t_pile **a, t_pile **b);

// Utils
int		check_already_sorted(t_pile **stack);
int		get_distance(t_pile **stack, int index);
int		get_min(t_pile **stack, int val);
void	make_top(t_pile **stack, int distance);
void	free_stack(t_pile **stack);

#endif