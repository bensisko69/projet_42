/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/29 14:17:13 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/12/04 12:08:09 by lrenoud-         ###   ########.fr       */
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
	if (noeud && room)
	{
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
	return (FALSE);
}

int						check_name_room(t_list *rooms)
{
	t_list	*it;
	t_list	*tmp;

	it = rooms;
	while (it)
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

int		check_cmd(t_list *rooms)
{
	t_list	*it;
	int		start;
	int		end;

	start = 0;
	end = 0;
	it = rooms;
	while (it)
	{
		if (ft_strcmp(((t_room*)(it->content))->name, "##start") == TRUE)
			start++;
		else if (ft_strcmp(((t_room*)(it->content))->name, "##end") == TRUE)
			end++;
		it = it->next;
	}
	if (start == 1 && end == 1)
		return (TRUE);
	return (FALSE);
}

int		lexer(t_map *map, t_list **list)
{
	if (check_cmd(map->rooms) == FALSE)
	{
		free_map(map);
		free_list((*list));
		ft_putendl_fd("ERROR", 2);
		exit (FALSE);
	}
	if (check_name_room(map->rooms) == FALSE)
		return (FALSE);
	if (check_name_noeud(map) == FALSE)
		return (FALSE);
	return (TRUE);
}
