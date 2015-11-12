/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/28 15:54:31 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/11/12 18:49:31 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_liste		*create_ellem(char *line)
{
	t_liste	*new_link;

	new_link = (t_liste *)malloc(sizeof(*new_link));
	new_link->type = 0;
	new_link->str = ft_strdup((const char*)line);
	new_link->next = new_link;
	new_link->previous = new_link;
	return (new_link);
}

void		ft_liste_push(char *line, t_liste **list)
{
	t_liste	*new_link;

	new_link = create_ellem(line);
	if ((*list) == NULL)
	{
		new_link->start = 1;
		*list = new_link;
	}
	else if ((*list) != NULL)
	{
		new_link->start = 0;
		while ((*list)->next->start != 1)
			*list = (*list)->next;
		new_link->next = (*list)->next;
		new_link->previous = *list;
		(*list)->next = new_link;
		new_link->next->previous = new_link;
	}
}

void		print_liste(t_liste *list)
{
	if (list == NULL)
	{
		ft_putendl("NULL");
		exit(0);
	}
	while (list->start != 1)
		list = list->next;
	while (list->next->start != 1)
	{
		// ft_putnbr(list->type);
		if (list->type == 2)
		{
			ft_putendl(list->str);
			ft_putnbr(list->room.type_room);
			ft_putendl(list->room.name);
		}
		list = list->next;
	}
	// ft_putnbr(list->type);
	// ft_putstr(list->str);
	if (list->type == 2)
	{
		ft_putendl(list->str);
		ft_putnbr(list->room.type_room);
		ft_putendl(list->room.name);
	}
	write(1, "\n", 1);
}

int		check_list(t_liste **liste)
{
	start_liste(liste);
	if ((*liste)->type == 0)
		return (FALSE);
	(*liste) = (*liste)->next;
	while ((*liste)->type != 0 && (*liste)->start != 1)
		(*liste) = (*liste)->next;
	if ((*liste)->type == 0)
		return (FALSE);
	return (TRUE);
}

void		init_room(t_liste **list)
{
	(*list)->room.x = 0;
	(*list)->room.y = 0;
	(*list)->room.type_room = 0;
	(*list)->room.name = NULL;
	(*list)->noeud.name_left = NULL;
	(*list)->noeud.name_right = NULL;
}

void		init(t_liste **list)
{
	start_liste(list);
	init_room(list);
	(*list) = (*list)->next;
	while ((*list)->start != 1)
	{
		init_room(list);
		(*list) = (*list)->next;
	}
}
