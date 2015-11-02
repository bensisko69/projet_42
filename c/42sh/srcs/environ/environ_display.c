/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ_display.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/02 18:16:20 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/05 16:22:50 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environ.h"

static void	show_one_variable(void *p_entry, void *data)
{
	t_map_entry	*entry;

	UNUSED(data);
	entry = (t_map_entry *)p_entry;
	ft_putstr(entry->key);
	ft_putchar(ENVIRON_VAR_SEPARATOR);
	if (entry->value)
		ft_putstr(entry->value);
	ft_putchar('\n');
}

void		environ_display(t_env_vars *vars)
{
	ft_map_foreach(*vars, show_one_variable, 0);
}
