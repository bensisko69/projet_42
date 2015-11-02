/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 14:48:20 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/27 13:17:07 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environ.h"

/*
** Functor to count map entries
*/
static void		increment(void *p_entry, void *data)
{
	size_t		*i;

	UNUSED(p_entry);
	i = (size_t *)data;
	++(*i);
}

static char		*variable_string(const char *key, const char *value)
{
	char		*str;
	size_t		key_len;
	size_t		value_len;

	key_len = ft_strlen(key);
	value_len = (value ? ft_strlen(value) : 0);
	str = (char *)malloc(sizeof(char) * (key_len + value_len + 2));
	str[key_len + value_len + 1] = '\0';
	ft_strncpy(str, key, key_len);
	str[key_len] = ENVIRON_VAR_SEPARATOR;
	if (value)
		ft_strncpy(str + key_len + 1, value, value_len);
	return (str);
}

static void		add_entry_to_array(void *p_entry, void *data)
{
	t_map_entry	*entry;
	char		***array;

	entry = (t_map_entry *)p_entry;
	array = (char ***)data;
	**array = variable_string(entry->key, entry->value);
	++(*array);
}

char			**environ_array(t_env_vars *vars)
{
	size_t		env_size;
	char		**array;
	char		**iarray;

	env_size = 0;
	ft_map_foreach(*vars, increment, &env_size);
	array = (char **)malloc(sizeof(char *) * (env_size + 1));
	array[env_size] = 0;
	iarray = array;
	ft_map_foreach(*vars, add_entry_to_array, &iarray);
	return (array);
}
