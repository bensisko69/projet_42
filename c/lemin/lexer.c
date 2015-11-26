/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/29 14:17:13 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/11/26 17:39:29 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int				check_left(char *name_left, t_list *room)
{
	t_list	*it;

	it = room;
	while (it)
	{
		if (ft_strcmp(((t_room*)(it->content))->name, name_left) == TRUE)
			return (TRUE);
		it = it->next;
	}
	return (FALSE);
}

static int				check_right(char *name_right, t_list *room)
{
	t_list	*it;

	it = room;
	while (it)
	{
		if (ft_strcmp(((t_room*)(it->content))->name, name_right) == TRUE)
			return (TRUE);
		it = it->next;
	}
	return (FALSE);
}

int						check_name_noeud(t_map *map)
{
	t_list *room;
	t_list *noeud;

	room = map->rooms;
	noeud = map->noeuds;
	while (noeud->next)
	{
		if (check_left(((t_noeud*)(noeud->content))->name_left, room)
			== FALSE)
			return (FALSE);
		if (check_right(((t_noeud*)(noeud->content))->name_right, room)
			== FALSE)
			return (FALSE);
		noeud = noeud->next;
	}
	return (TRUE);
}

int						check_name_room(t_list *rooms)
{
	t_list	*it;
	t_list	*tmp;

	it = rooms;
	while (it->next)
	{
		tmp = it->next;
		while(tmp)
		{
			if (ft_strcmp(((t_room*)(tmp->content))->name,
				((t_room*)(it->content))->name) == TRUE)
				return (FALSE);
			tmp = tmp->next;
		}
		it = it->next;
	}
	return (TRUE);
}

int		lexer(t_map *map)
{
	if (check_name_room(map->rooms) == FALSE)
		return (FALSE);
	if (check_name_noeud(map) == FALSE)
		return (FALSE);
	return (TRUE);
}
