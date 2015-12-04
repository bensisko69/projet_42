/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 13:32:05 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/12/04 13:33:08 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_list(t_list *list)
{
	t_list  *it;

	while (list)
	{
		it = list;
		free(it->content);
		list = list->next;
		free(it);
	}
}

void	free_room(t_list *room)
{
	t_list  *it;

	it = room;
	while (room)
	{
		it = room;
		free(((t_room*)(it->content))->name);
		room = room->next;
		free(it->content);
		free(it);
	}
}

void	free_noeud(t_list *noeud)
{
	t_list  *it;

	it = noeud;
	while (noeud)
	{
		it = noeud;
		free(((t_noeud*)(it->content))->name_left);
		free(((t_noeud*)(it->content))->name_right);
		noeud = noeud->next;
		free(it->content);
		free(it);
	}
}

void	free_map(t_map *map)
{
	free_room(map->rooms);
	free_noeud(map->noeuds);
}
