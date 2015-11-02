/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 23:28:24 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/27 15:32:30 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

static void			free_key_map_entry(void *key, void *value)
{
	UNUSED(key);
	UNUSED(value);
}

void				free_key_map(void)
{
	t_map			*key_map;

	key_map = get_key_map();
	ft_map_delete(*key_map, free_key_map_entry);
	free(key_map);
}

static void			add_to_map(t_map *map, char *sequence, t_seq_action action)
{
	t_map_entry		entry;

	entry.key = sequence;
	entry.value = action;
	ft_map_insert(*map, entry, (t_simple_hash_func)ft_djb2);
}

static void			init_key_map(t_map *key_map)
{
	add_to_map(key_map, SEQ_CTRL_D, on_key_ctrl_d);
	add_to_map(key_map, SEQ_CTRL_L, on_key_ctrl_l);
	add_to_map(key_map, SEQ_CTRL_W, on_key_ctrl_w);
	add_to_map(key_map, SEQ_CTRL_K, on_key_ctrl_k);
	add_to_map(key_map, SEQ_CTRL_A, on_key_ctrl_a);
	add_to_map(key_map, SEQ_CTRL_E, on_key_ctrl_e);
	add_to_map(key_map, SEQ_CTRL_U, on_key_ctrl_u);
	add_to_map(key_map, SEQ_CTRL_H, on_key_ctrl_h);
	add_to_map(key_map, SEQ_CTRL_G, on_key_ctrl_g);
	add_to_map(key_map, SEQ_CTRL_C, on_key_ctrl_c);
	add_to_map(key_map, SEQ_CTRL_F, on_key_ctrl_f);
}

t_map				*get_key_map(void)
{
	static t_map	*key_map = 0;

	if (!key_map)
	{
		key_map = (t_map *)ft_memalloc(sizeof(t_map));
		init_key_map(key_map);
		add_to_map(key_map, SEQ_NEW_LINE, on_key_new_line);
		add_to_map(key_map, SEQ_TAB, on_key_tab);
		add_to_map(key_map, SEQ_BACKSPACE, on_key_backspace);
		add_to_map(key_map, SEQ_ALT_LEFT, on_key_alt_left);
		add_to_map(key_map, SEQ_ALT_RIGHT, on_key_alt_right);
		add_to_map(key_map, SEQ_ALT_UP, on_key_alt_up);
		add_to_map(key_map, SEQ_ALT_DOWN, on_key_alt_down);
		add_to_map(key_map, SEQ_LEFT_ARROW, on_key_left_arrow);
		add_to_map(key_map, SEQ_RIGHT_ARROW, on_key_right_arrow);
		add_to_map(key_map, SEQ_UP_ARROW, on_key_up_arrow);
		add_to_map(key_map, SEQ_DOWN_ARROW, on_key_down_arrow);
	}
	return (key_map);
}
