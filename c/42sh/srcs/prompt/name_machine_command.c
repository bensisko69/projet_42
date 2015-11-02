/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_machine_command.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 15:33:37 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/03/20 17:50:35 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"
#include "environ.h"

char		*name_machine_command(t_context *context, size_t n)
{
	char	name[256];

	UNUSED(n);
	UNUSED(context);
	if (gethostname(name, 256) == 0)
		return (ft_strdup(name));
	return (ft_strdup(MACHINE_NAME_ERROR));
}
