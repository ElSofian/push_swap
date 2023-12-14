/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:04:15 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/14 11:12:19 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stddef.h>

/*
 * Args at the command line are
 * spaced separated strings
*/
static int	count_words(char *str, char separator)
{
	int		count;
	bool	inside_word;

	count = 0;
	while (*str)
	{
		inside_word = false;
		while (*str == separator && *str)
			++str;
		while (*str != separator && *str)
		{
			if (!inside_word)
			{
				++count;
				inside_word = true;
			}
			++str;
		}
	}
	return (count);
}

/*
 * I exploit static variables
 * which are basically 
 * "Global private variables"
 * i can access it only via the get_next_word function
*/
static char	*put_word(char *str, char separator)
{
	int			i;
	int			len;
	static int	cursor = 0;
	char		*next_str;

	len = 0;
	i = 0;
	while (str[cursor] == separator)
		++cursor;
	while ((str[cursor + len] != separator) && str[cursor + len])
		++len;
	next_str = malloc((size_t)len * sizeof(char) + 1);
	if (!next_str)
		return (NULL);
	while ((str[cursor] != separator) && str[cursor])
		next_str[i++] = str[cursor++];
	next_str[i] = '\0';
	return (next_str);
}

/*
 * I recreate an av in the HEAP
 *
 * +2 because i want to allocate space
 * for the "\0" Placeholder and the final NULL
 *
 * vector_strings-->[p0]-> "\0" Placeholder to mimic av
 * 				 |->[p1]->"Hello"
 * 				 |->[p2]->"how"
 * 				 |->[p3]->"Are"
 * 				 |->[..]->"..""
 * 				 |->[NULL]
*/
char	**split(char *str, char separator)
{
	int		i;
	int		words_count;
	char	**tab;

	i = 0;
	words_count = count_words(str, separator);
	if (!words_count)
		exit(EXIT_FAILURE);
	tab = malloc(sizeof(char *) * (words_count + 2));
	if (tab == NULL)
		return (NULL);
	while (words_count-- >= 0)
	{
		if (i == 0)
		{
			tab[i] = malloc(sizeof(char));
			if (!tab[i])
				return (NULL);
			tab[i++][0] = '\0';
			continue ;
		}
		tab[i++] = put_word(str, separator);
	}
	tab[i] = NULL;
	return (tab);
}
