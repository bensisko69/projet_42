/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 17:36:05 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/27 13:23:11 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interpreter.h"

static void		free_node_map_entry(void *key, void *value)
{
	UNUSED(key);
	UNUSED(value);
}

void			free_node_map(void)
{
	t_map		*node_map;

	node_map = get_node_map();
	ft_map_delete(*node_map, free_node_map_entry);
	free(node_map);
}

t_uint64		token_type_hash(const void *p_type)
{
	t_token_type	*type;

	type = (t_token_type *)p_type;
	return ((t_uint64)*type);
}

static void		add_to_map(t_map *map, t_token_type type, t_evaluator evaluator)
{
	t_map_entry	entry;

	entry.key = &type;
	entry.value = evaluator;
	ft_map_insert(*map, entry, token_type_hash);
}

t_map			*get_node_map(void)
{
	static t_map	*node_map = 0;

	if (!node_map)
	{
		node_map = (t_map *)ft_memalloc(sizeof(t_map));
		add_to_map(node_map, OP_SEMI_COLON, eval_both);
		add_to_map(node_map, OP_AMPERSAND, eval_in_background);
		add_to_map(node_map, OP_AND, eval_if_and);
		add_to_map(node_map, OP_OR, eval_if_or);
	}
	return (node_map);
}
