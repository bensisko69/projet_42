/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_machine_truncated_command.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 16:08:07 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/03/20 17:50:55 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"
#include "environ.h"

char		*name_machine_truncated_command(t_context *context, size_t n)
{
	char	name[256];
	char	*dot_index;

	UNUSED(n);
	UNUSED(context);
	if (gethostname(name, 256) == 0)
	{
		dot_index = ft_strchr(name, '.');
		if (dot_index)
			return (ft_strsub(name, 0, dot_index - name));
		return (ft_strdup(name));
	}
	return (ft_strdup(MACHINE_NAME_ERROR));
}
