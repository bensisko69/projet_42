/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_name.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/16 16:43:07 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/16 16:56:55 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_uint64		signal_id_hash(const void *p_id)
{
	const int		*id;

	id = (const int *)p_id;
	return ((t_uint64)*id);
}

char			*signal_name(int signal_id)
{
	char	*name;

	name = (char *)ft_map_get(*get_signal_names_map(),
								&signal_id,
								signal_id_hash);
	if (!name)
		name = SIG_NAME_UNKNOWN;
	return (name);
}
