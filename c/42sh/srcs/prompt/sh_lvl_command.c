/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_lvl_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 15:27:49 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/03/23 01:56:07 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"
#include "environ.h"

char		*sh_lvl_command(t_context *context, size_t n)
{
	char	*lvl;

	UNUSED(n);
	lvl = environ_get(context, VAR_SHELL_LVL);
	if (!lvl)
		lvl = DEFAULT_SH_LVL;
	return (ft_strdup(lvl));
}
