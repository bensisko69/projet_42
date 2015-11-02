/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 17:44:47 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/05 17:51:04 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static void	show_one_variable(void *p_entry, void *data)
{
	t_map_entry	*entry;

	UNUSED(data);
	entry = (t_map_entry *)p_entry;
	ft_putstr(entry->key);
	ft_putstr(VARS_SEPARATOR);
	if (entry->value)
		ft_putstr(entry->value);
	ft_putchar('\n');
}

int			b_vars(t_context *context, t_list *args)
{
	UNUSED(args);
	ft_map_foreach(*context->vars, show_one_variable, 0);
	return (BUILTIN_SUCCESS);
}
