/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 07:24:07 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/14 17:04:00 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_pile
{
	int					nb;
	int					pos;
	int					moves_count;
	bool				higher_than_median;
	bool				lowest;
	struct s_pile	*target;
	struct s_pile	*next;
	struct s_pile	*prev;
}				t_pile;	

//*** Handle input ./push_swap "1 -42 1337" ***
char	**split(char *str, char separator);

// Errors
void	error(t_pile **a, char **av, bool is_string);
int		check_doubles(t_pile *a, int nbr);
int		check_format(char *str_nbr);
void	ft_free_av(char **av);
void	free_pile(t_pile **pile);

//*** Pile creation ***
void	initialize(t_pile **a, char **av, bool is_string);
void	init_nodes(t_pile *a, t_pile *b);
void	set_pos(t_pile *pile);
void	set_price(t_pile *a, t_pile *b);
void	set_lower(t_pile *b);

//*** linked list utils ***
int		pile_len(t_pile *pile);
bool	is_sorted(t_pile *pile);
void	append_node(t_pile **pile, int nbr);
void	final_rotation(t_pile **pile, t_pile *n, char c);
t_pile	*find_last_node(t_pile *head);
t_pile	*find_smallest(t_pile *pile);
t_pile	*return_lower(t_pile *pile);

// Algo
void	tiny_sort(t_pile **a);
void	handle_five(t_pile **a, t_pile **b);
void	push_swap(t_pile **a, t_pile **b);

// Moves
// 		Swap

void	sa(t_pile **a, bool checker);
void	sb(t_pile **b, bool checker);
void	ss(t_pile **a, t_pile **b, bool checker);

// 		Rotate
void	ra(t_pile **a, bool checker);
void	rb(t_pile **b, bool checker);
void	rr(t_pile **a, t_pile **b, bool checker);

// 		Reverse rotate
void	rra(t_pile **a, bool checker);
void	rrb(t_pile **b, bool checker);
void	rrr(t_pile **a, t_pile **b, bool checker);

// 		Push
void	pa(t_pile **a, t_pile **b, bool checker);
void	pb(t_pile **b, t_pile **a, bool checker);

#endif
