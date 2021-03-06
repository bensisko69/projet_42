/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 13:39:45 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/26 18:28:26 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	insert_cmp(void *c, size_t c_s, void *n, size_t n_s)
{
	t_map_entry	*c_entry;
	t_map_entry	*n_entry;

	UNUSED(c_s);
	UNUSED(n_s);
	c_entry = (t_map_entry *)c;
	n_entry = (t_map_entry *)n;
	return (c_entry->hash_ - n_entry->hash_);
}

void		ft_map_insert(t_map map, t_map_entry entry, t_simple_hash_func h_f)
{
	t_btree	*node;

	entry.hash_ = h_f(entry.key);
	node = ft_btree_new(&entry, sizeof(t_map_entry));
	ft_btree_insert(&map[entry.hash_ % MAP_TREE_SIZE], node, insert_cmp);
}
