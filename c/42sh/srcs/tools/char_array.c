/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/23 10:49:27 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/27 13:32:18 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

size_t			char_array_map(char **array, t_char_array_functor functor)
{
	size_t	total;
	size_t	i;

	total = 0;
	if (array)
	{
		i = 0;
		while (array[i])
			total += functor(array[i++]);
	}
	return (total);
}

static size_t	one(const char *str)
{
	(void)str;
	return (1);
}

size_t			char_array_size(char **array)
{
	if (array)
		return (char_array_map(array, (t_char_array_functor)one));
	return (0);
}

void			char_array_free(char **array)
{
	char_array_map(array, (t_char_array_functor)free);
	free(array);
}
