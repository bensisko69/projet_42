/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/28 16:00:45 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/12/04 12:04:09 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** GRAMM:
** exp			:=	[comment]* NBR [room]+ [tube]+ [comment]*
** room			:=	[comment]* [commande]? WORD NBR{2}
** tube			:=	[comment]* NBR - NBR
** commande		:=	DIEZE DIEZE [WORD]*
** comment		:=	DIEZE [WORD]*
*/

#include "lemin.h"

int		parse_nbr(t_list **liste,t_map *map)
{
	int	i;

	i = 0;
	while (ft_isdigit(((char *)((*liste)->content))[i]) == 1)
			i++;
	if (((char *)((*liste)->content))[i] == '\0')
	{
		map->nb_ants = ft_atoi((*liste)->content);
		(*liste) = (*liste)->next;
		return (TRUE);
	}
	return (FALSE);
}

int		parse_tube(t_list **liste,t_map *map)
{
	if ((*liste) && parse_noeud(liste, map) == TRUE)
	{
		if (*liste)
		{
			(*liste) = (*liste)->next;
			while ((*liste) && parse_noeud(liste, map) == TRUE)
				(*liste) = (*liste)->next;
		}
	}
	else
		return (FALSE);
	return (TRUE);
}

int		parse_room(t_list **liste,t_map *map)
{
	t_room	*tmp;

	tmp = NULL;
	if (parse_cmd(liste, map) == TRUE)
		return (TRUE);
	else if (parse_name_room(liste) == TRUE)
	{
		tmp = struct_room(2,liste);
		ft_lstappend(&map->rooms, ft_lstnew(tmp, sizeof(t_room)));
		free(tmp);
		return (TRUE);
	}
	return (FALSE);
}

int		parse_exp(t_list **liste,t_map *map)
{
	if ((*liste) && parse_nbr(liste, map) == FALSE )
		return (FALSE);
	if ((*liste) && parse_room(liste, map) == TRUE)
	{
		(*liste) = (*liste)->next;
		if (*liste)
		{
			while (parse_room(liste, map) == TRUE)
				(*liste) = (*liste)->next;
		}
	}
	if ((*liste) && parse_tube(liste, map) == FALSE)
		return (FALSE);
	return (TRUE);
}

int		parse(t_list *liste,t_map *map)
{
	t_list	*it;

	it = liste;
	if (parse_exp(&it, map) ==  FALSE)
		return (FALSE);
	return (TRUE);
}
