/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 16:57:56 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/13 17:06:32 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int	is_relative_or_absolute(const char *name)
{
	return (ft_strchr(name, '/') != 0);
}

char		*get_command_path(t_context *context, const char *command_name)
{
	char	*command_path;

	if (is_relative_or_absolute(command_name))
		return ((char *)command_name);
	command_path = (char *)ft_map_get(*context->commands,
										(char *)command_name,
										(t_simple_hash_func)ft_djb2);
	return (command_path);
}
