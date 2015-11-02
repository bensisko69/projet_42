/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 16:41:44 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/14 15:10:37 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** Functor to deallocate a variable hashmap properly
** Both the key and the value must be freed
*/
static void	free_variable(void *key, void *value)
{
	free(key);
	free(value);
}

char		*variables_get(t_vars *vars, const char *key)
{
	char		*value;

	value = ft_map_get(*vars, (char *)key, (t_simple_hash_func)ft_djb2);
	return (value);
}

void		variables_set(t_vars *vars, const char *key, const char *value)
{
	t_map_entry	*old_entry;
	t_map_entry	new_entry;

	old_entry = ft_map_get_p(*vars, (char *)key, (t_simple_hash_func)ft_djb2);
	if (old_entry)
	{
		free(old_entry->value);
		old_entry->value = (value ? ft_strdup(value) : 0);
	}
	else
	{
		new_entry.key = ft_strdup(key);
		new_entry.value = (value ? ft_strdup(value) : 0);
		ft_map_insert(*vars, new_entry, (t_simple_hash_func)ft_djb2);
	}
}

void		variables_remove(t_vars *vars, const char *key)
{
	ft_map_remove(*vars, (char *)key,
					(t_simple_hash_func)ft_djb2, free_variable);
}

void		variables_delete(t_vars *vars)
{
	ft_map_delete(*vars, free_variable);
}
