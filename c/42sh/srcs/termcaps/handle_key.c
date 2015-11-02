/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 22:52:08 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/27 13:05:09 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

static t_seq_action	get_seq_action(char *key)
{
	t_seq_action	action;

	action = (t_seq_action)ft_map_get(*get_key_map(),
										key,
										(t_simple_hash_func)ft_djb2);
	return (action);
}

int					handle_key(t_context *context, t_line_edit *le,
								char *key, size_t len)
{
	t_seq_action	action;

	action = get_seq_action(key);
	if (action)
		return (action(context, le));
	line_insert(le, key, len);
	return (READ_CONTINUE);
}
