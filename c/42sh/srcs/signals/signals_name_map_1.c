/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_name_map_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/16 16:49:24 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/16 17:04:21 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void			add_to_map(t_map *map, int sig, char *name)
{
	t_map_entry		entry;

	entry.key = &sig;
	entry.value = name;
	ft_map_insert(*map, entry, signal_id_hash);
}

static void			fill_signal_map_1(t_map *map)
{
	add_to_map(map, 1, SIG_NAME_HUP);
	add_to_map(map, 2, SIG_NAME_INT);
	add_to_map(map, 3, SIG_NAME_QUIT);
	add_to_map(map, 4, SIG_NAME_ILL);
	add_to_map(map, 5, SIG_NAME_TRAP);
	add_to_map(map, 6, SIG_NAME_ABRT);
	add_to_map(map, 7, SIG_NAME_EMT);
	add_to_map(map, 8, SIG_NAME_FPE);
	add_to_map(map, 9, SIG_NAME_KILL);
	add_to_map(map, 10, SIG_NAME_BUS);
	add_to_map(map, 11, SIG_NAME_SEGV);
	add_to_map(map, 12, SIG_NAME_SYS);
	add_to_map(map, 13, SIG_NAME_PIPE);
	add_to_map(map, 14, SIG_NAME_ALRM);
	add_to_map(map, 15, SIG_NAME_TERM);
	add_to_map(map, 16, SIG_NAME_URG);
}

static void			fill_signal_map_2(t_map *map)
{
	add_to_map(map, 17, SIG_NAME_STOP);
	add_to_map(map, 18, SIG_NAME_TSTP);
	add_to_map(map, 19, SIG_NAME_CONT);
	add_to_map(map, 20, SIG_NAME_CHLD);
	add_to_map(map, 21, SIG_NAME_TTIN);
	add_to_map(map, 22, SIG_NAME_TTOU);
	add_to_map(map, 23, SIG_NAME_IO);
	add_to_map(map, 24, SIG_NAME_XCPU);
	add_to_map(map, 25, SIG_NAME_XFSZ);
	add_to_map(map, 26, SIG_NAME_VTALRM);
	add_to_map(map, 27, SIG_NAME_PROF);
	add_to_map(map, 28, SIG_NAME_WINCH);
	add_to_map(map, 29, SIG_NAME_INFO);
	add_to_map(map, 30, SIG_NAME_USR1);
	add_to_map(map, 31, SIG_NAME_USR2);
}

t_map				*get_signal_names_map(void)
{
	static t_map	*signal_names_map = 0;

	if (!signal_names_map)
	{
		signal_names_map = (t_map *)ft_memalloc(sizeof(t_map));
		fill_signal_map_1(signal_names_map);
		fill_signal_map_2(signal_names_map);
	}
	return (signal_names_map);
}
