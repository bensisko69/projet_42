/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/29 14:17:13 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/11/11 19:21:13 by lrenoud-         ###   ########.fr       */
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
			if (ft_strcmp(tmp->room.name, (*liste)->room.name) == TRUE)
				return (FALSE);
			tmp = tmp->next;
		}
		(*liste) = (*liste)->next;
	}
	return (TRUE);
}

int		lexer(t_liste **liste)
{
	while ((*liste)->start != 1)
		(*liste) = (*liste)->next;
	if (check_name_room(liste) == FALSE)
	{
		ft_error(3, (*liste)->room.name);
		return (FALSE);
	}
	return (TRUE);
}
