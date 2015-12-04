/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   labyrinth.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 14:24:58 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/12/04 15:51:17 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_lab	*struct_lab(char *str)
{
	t_lab	*new;

	new = (t_lab*)malloc(sizeof(*new));
	new->name = ft_strdup(str);
	return (new);
}

void	created_lab(t_list *noeuds, t_list *rooms)
{
	t_list	*it_room;
	t_list	*it_noeud;

	it_noeud = noeuds;
	while (it_noeud)
	{
		it_room = rooms;
		while (ft_strcmp(((t_room*)(it_room->content))->name,
		((t_noeud*)(it_noeud->content))->name_left) == TRUE)

	}
}

void		labyrinth(t_map *map)
{
	if (map->noeuds && map->rooms)
		created_lab(map->noeuds, map->rooms);
}
