/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_name_map_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/16 17:00:29 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/16 17:04:31 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void			free_signal_name_entry(void *key, void *value)
{
	UNUSED(key);
	UNUSED(value);
}

void				free_signal_names_map(void)
{
	t_map			*signal_names_map;

	signal_names_map = get_signal_names_map();
	ft_map_delete(*signal_names_map, free_signal_name_entry);
	free(signal_names_map);
}
