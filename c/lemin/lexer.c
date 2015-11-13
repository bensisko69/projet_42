/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/29 14:17:13 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/11/13 14:42:06 by lrenoud-         ###   ########.fr       */
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

int		check_name_room(t_liste **liste)
{
	start_liste(liste);
	search_type(liste, 2);

	return (TRUE);
}

int		lexer(t_liste **liste)
{
	start_liste(liste);
	if (check_name_room(liste) == FALSE)
		return (FALSE);
	if (check_noeud(liste) == FALSE)
		return (FALSE);
	if (check_name_noeud(liste) = FALSE)
		return (FALSE);
	return (TRUE);
}


/* type dans la structure.
** 1 type NBR
** 2 type ROOM
** 3 type start
** 4 type end
** 5 type COMMENT
** 6 type TUBE
** start
** 1 = 1er ellem
** 0 = ellem suivant
** room
** 0 autre
** 1 start
** 2 end
*/
