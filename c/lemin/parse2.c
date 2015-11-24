/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/29 13:46:24 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/11/24 17:13:19 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_noeud		struct_noeud(t_liste **liste)
{
	char	**tab;
	t_noeud	noeud;

	tab = ft_strsplit((*liste)->str, '-');
	noeud.name_left = tab[0];
	noeud.name_right = tab[1];
	return (noeud);
}

int		parse_noeud(t_liste **liste, t_map *map)
{
	int	i;

	i = 0;
	if ((*liste)->str[0] == 'L' || (*liste)->str[0] == '#')
		return (FALSE);
	while (ft_isalnum((*liste)->str[i]) == 1 && (*liste)->str[i])
		i++;
	if ((*liste)->str[i] != ' ' && (*liste)->str[i] && (*liste)->str[i] == '-')
		i++;
	while (ft_isalnum((*liste)->str[i]) == 1 && (*liste)->str[i])
		i++;
	if ((*liste)->str[i] == '\0')
	{
		ft_lstappend(&map->noeuds, ft_lstnew(struct_noeud(liste), sizeof(t_noeud)));
		return (TRUE);
	}
	return (FALSE);
}

t_room		struct_room(int type, t_liste **liste)
{
	char	**tab;
	t_room	room;

	tab = ft_strsplit((*liste)->str, ' ');
	room.name = tab[0];
	room.x = ft_atoi(tab[1]);
	room.y = ft_atoi(tab[2]);
	room.type_room = type;
	return (room);
}

int		parse_cmd(t_liste **liste, t_map *map)
{
	if (ft_strncmp((*liste)->str, "##", 2) == TRUE)
	{
		if (ft_strcmp((*liste)->str, "##start") == TRUE)
		{
			(*liste) = (*liste)->next;
			if (parse_name_room(liste) == FALSE)
				return (FALSE);
			ft_lstappend(&map->rooms, ft_lstnew(struct_room(3, liste), sizeof(t_room)));
		}
		else if (ft_strcmp((*liste)->str, "##end") == TRUE)
		{
			(*liste) = (*liste)->next;
			if (parse_name_room(liste) == FALSE)
				return (FALSE);
			ft_lstappend(&map->rooms, ft_lstnew(struct_room(4, liste), sizeof(t_room)));
		}
		else
			return (FALSE);
		(*liste) = (*liste)->next;
		return (TRUE);
	}
	return (2);
}

int		parse_name_room(t_liste **liste)
{
	int	i;

	i = 0;
	if ((*liste)->str[0] == 'L' || (*liste)->str[0] == '#')
		return (FALSE);
	while (ft_isalnum((int)(*liste)->str[i]) == 1 && (*liste)->str[i])
		i++;
	if ((*liste)->str[i] == ' ' && (*liste)->str[i] && (*liste)->str[i] != '-')
		i++;
	while (ft_isdigit((int)(*liste)->str[i]) == 1 && (*liste)->str[i])
		i++;
	if ((*liste)->str[i] == ' ' && (*liste)->str[i])
		i++;
	while (ft_isdigit((int)(*liste)->str[i]) == 1 && (*liste)->str[i])
		i++;
	if ((*liste)->str[i] == '\0')
		return (TRUE);
	return (FALSE);
}
