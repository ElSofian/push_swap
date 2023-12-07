/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:28:37 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/07 13:56:20 by soelalou         ###   ########.fr       */
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

typedef struct	s_pile
{
	struct s_pile	*prev;
	int				nb;
	int				pos;
	struct s_pile	*next;
}					t_pile;

void	error(void);
void	check_doubles(t_pile *a);
void	check_int(char *str);
void	freepile(t_pile **lst);

#endif