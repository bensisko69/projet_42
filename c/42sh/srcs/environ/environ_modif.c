/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ_modif.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 17:19:28 by kpoirier          #+#    #+#             */
/*   Updated: 2014/03/27 13:21:41 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environ.h"

char	*environ_get(t_context *context, const char *key)
{
	return (variables_get(context->env_vars, key));
}

void	environ_set(t_context *context, const char *key, const char *value)
{
	variables_set(context->env_vars, key, value);
	if (!ft_strcmp(key, VAR_PATH))
		list_commands(context);
}

void	environ_remove(t_context *context, const char *key)
{
	variables_remove(context->env_vars, key);
	if (!ft_strcmp(key, VAR_PATH))
		commands_delete(context->commands);
}
