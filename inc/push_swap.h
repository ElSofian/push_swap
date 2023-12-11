/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:28:37 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/11 10:33:52 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define RESTART "\033[0m"

typedef struct s_pile
{
	int				nb;
	int				pos;
	struct s_pile	*next;
}					t_pile;

// Errors

void	error(char *str);
void	check(int ac, char **av);
void	check_int(char *str);
void	check_int_arg(char *str);
void	check_contain(int nb, int start, char **av);
void	check_already_sorted(t_pile **a, t_pile **b);

// Utils

void	print_list(t_pile *head);
int		is_sorted(t_pile **stack);
int		get_distance(t_pile **stack, int pos);
void	make_top(t_pile **stack, int distance);
t_pile	*get_next_min(t_pile **stack);
void	get_pos(t_pile **stack);
int		get_min(t_pile **stack, int val);

// Lists

void	freepile(t_pile **lst);
void	lstadd_back(t_pile **lst, t_pile *new);
int		lstsize(t_pile *lst);
t_pile	*lstnew(int nb);
t_pile	*lstlast(t_pile *lst);

// Moves

int		push(t_pile **dst, t_pile **src);
int		pa(t_pile **a, t_pile **b);
int		pb(t_pile **a, t_pile **b);

int		reverse_rotate(t_pile **stack);
int		rra(t_pile **a);
int		rrb(t_pile **b);
int		rrr(t_pile **a, t_pile **b);

int		rotate(t_pile **stack);
int		ra(t_pile **a);
int		rb(t_pile **b);
int		rr(t_pile **a, t_pile **b);

int		swap(t_pile **stack);
int		sa(t_pile **a);
int		sb(t_pile **b);
int		ss(t_pile **a, t_pile **b);

// Algorithms

void	sort_3(t_pile **a);
void	handler_3(t_pile **a, t_pile *head, int min, int next_min);
void	sort_4(t_pile **a, t_pile **b);
void	sort_5(t_pile **a, t_pile **b);
void	simple_sort(t_pile **a, t_pile **b);

int		get_max_bits(t_pile **stack);
void	radix_sort(t_pile **a, t_pile **b);

// Main

void	sort(t_pile **a, t_pile **b);
void	initialize(t_pile **a, int ac, char **av);

#endif