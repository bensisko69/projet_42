/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 14:45:42 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/27 13:48:45 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environ.h"

/*
** Iterates over <environ> and extracts the key and the value of each variable
** to store them in <vars>
** A variable is formatted '<key>=<value>'
** The first '=' sign will be interpreted as the separator
*/
void			environ_init(t_env_vars *vars)
{
	size_t		i;
	char		*separator;
	t_map_entry	entry;
	extern char	**environ;

	i = 0;
	while (environ[i])
	{
		separator = ft_strchr(environ[i], ENVIRON_VAR_SEPARATOR);
		entry.key = ft_strsub(environ[i], 0, separator - environ[i]);
		entry.value = ft_strdup(separator + 1);
		ft_map_insert(*vars, entry, (t_simple_hash_func)ft_djb2);
		++i;
	}
}

void			environ_delete(t_env_vars *vars)
{
	variables_delete(vars);
}
