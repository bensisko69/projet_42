/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/28 16:00:45 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/11/24 17:19:26 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*GRAMM:
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
	while (ft_isdigit((*liste)->content)[i] == 1)
		i++;
	if ((*liste)->content[i] == '\0')
	{
		map->nb_ants = ft_atoi((*liste)->content);
		(*liste) = (*liste)->next;
		return (TRUE);
	}
	return (FALSE);
}

int		parse_tube(t_list **liste,t_map *map)
{
	if (parse_noeud(liste, map) == TRUE)
	{
		while (parse_noeud(liste, map) == TRUE)
			(*liste) = (*liste)->next;
	}
	else
		return (FALSE);
	return (TRUE);
}

int		parse_room(t_list **liste,t_map *map)
{
	if (parse_cmd(liste, map) == FALSE)
		return (FALSE);
	if (parse_name_room(liste) == TRUE)
	{
		ft_lstappend(map->rooms, ft_lstnew(struct_room(2,liste), sizeof(t_room)));
		return (TRUE);
	}
	return (FALSE);
}

int		parse_exp(t_list **liste,t_map *map)
{
	if (parse_nbr(liste, map) == FALSE)
		return (FALSE);
	if (parse_room(liste, map) == TRUE)
	{
		while (parse_room(liste) == TRUE)
			(*liste) = (*liste)->next;
	}
	if (parse_tube(liste, map) == FALSE)
		return (FALSE);
	return (TRUE);
}

int		parse(t_list **liste,t_map *map)
{
	if (parse_exp(liste, map) ==  FALSE)
		return (FALSE);
	return (TRUE);
}
