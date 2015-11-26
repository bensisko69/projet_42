/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/29 14:17:13 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/11/26 15:01:17 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		check_name_room(t_map *map)
{
	t_list	*tmp;
	t_list	*it;

	it = map->rooms;
	while (map)
	{
		tmp = map->rooms->next;
		while (tmp->next)
		{
			if (ft_strcmp(((t_room*)(tmp->content))->name, ((t_room*)(it->content))->name) == TRUE)
					return (FALSE);
			tmp = tmp->next;
		}
		it = it->next;
	}
	return (TRUE);
}

int		double_name(t_map *map)
{
	while ((*liste)->next->start != 1)
	{
		while ((*liste)->type == 5)
			(*liste) = (*liste)->next;
		if (ft_strcmp((*liste)->noeud.name_left, (*liste)->noeud.name_right)
			== TRUE)
			return (FALSE);
		(*liste) = (*liste)->next;
	}
	return (TRUE);
}

int		check_noeud(t_liste **liste)
{
	t_liste	*tmp;
	while ((*liste)->next->start != 1)
	{
		while ((*liste)->type == 5)
			(*liste) = (*liste)->next;
		tmp = (*liste)->next;
		while (tmp->next->start != 1)
		{
			while (tmp->type == 5)
				tmp = tmp->next;
			if (ft_strcmp(tmp->str, (*liste)->str) == TRUE)
			{
				ft_error(4, (*liste)->str);
				return (FALSE);
			}
			tmp = tmp->next;
		}
		(*liste) = (*liste)->next;
	}
	if (double_name(liste) == FALSE)
		return (FALSE);
	return (TRUE);
}

static int	check(char *str, t_liste *liste)
{
	while (liste->type == 2)
	{
		if (ft_strcmp(liste->room.name, str) == TRUE)
			return (TRUE);
		liste = liste->next;
		while (liste->type == 5 || liste->type == 3 || liste->type == 4)
			liste = liste->next;
	}
	return (FALSE);
}

int		check_name_noeud(t_liste **liste)
{
	t_liste *tmp;

	tmp = (*liste);
	while (tmp->type == 6)
	{
		if (check(tmp->noeud.name_left, (*liste)) == FALSE)
			return (FALSE);
		if (check(tmp->noeud.name_right, (*liste)) == FALSE)
			return (FALSE);
		tmp = tmp->next;
	}
	return (TRUE);
}

int		lexer(t_map *map)
{
	if (check_name_room(map) == FALSE)
		return (FALSE);
	if (check_noeud(map) == FALSE)
		return (FALSE);
	if (check_name_noeud(liste) == FALSE)
		return (FALSE);
	return (TRUE);
}
