/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/29 14:17:13 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/11/23 15:29:36 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		check_name_room(t_liste **liste)
{
	t_liste	*tmp;

	while ((*liste)->type == 5 || (*liste)-> type == 1)
		(*liste) = (*liste)->next;
	while ((*liste)->next->type != 6)
	{
		while ((*liste)->type == 5 || (*liste)->type == 3 || (*liste)->type == 4)
			(*liste) = (*liste)->next;
		tmp = (*liste)->next;
		while (tmp->next->type != 6)
		{
			while (tmp->type == 5 || tmp->type == 3 || tmp->type == 4)
				tmp = tmp->next;
			if (ft_strcmp(tmp->room.name, (*liste)->room.name) == TRUE && tmp->room.name)
				{
					ft_error(3, (*liste)->room.name);
					return (FALSE);
				}
			tmp = tmp->next;
		}
		(*liste) = (*liste)->next;
	}
	return (TRUE);
}

int		double_name(t_liste **liste)
{
	start_liste(liste);
	search_type(liste, 6);
	while ((*liste)->next->start != 1)
	{
		while ((*liste)->type == 5)
			(*liste) = (*liste)->next;
		if (ft_strcmp((*liste)->noeud.name_left, (*liste)->noeud.name_right)
			== TRUE)
		{
			ft_error(5, (*liste)->str);
			return (FALSE);
		}
		(*liste) = (*liste)->next;
	}
	return (TRUE);
}

int		check_noeud(t_liste **liste)
{
	t_liste	*tmp;
	start_liste(liste);
	search_type(liste, 6);
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
	ft_error(6, str);
	return (FALSE);
}

int		check_name_noeud(t_liste **liste)
{
	t_liste *tmp;

	start_liste(liste);
	tmp = (*liste);
	search_type(liste, 2);
	search_type(&tmp, 6);
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

int		lexer(t_liste **liste)
{
	start_liste(liste);
	if (check_name_room(liste) == FALSE)
		return (FALSE);
	if (check_noeud(liste) == FALSE)
		return (FALSE);
	if (check_name_noeud(liste) == FALSE)
		return (FALSE);
	return (TRUE);
}
