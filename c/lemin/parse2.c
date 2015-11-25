/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/29 13:46:24 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/11/25 16:18:08 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_noeud		*struct_noeud(t_list **liste)
{
	char	**tab;
	t_noeud	*noeud;

	noeud = (t_noeud *)malloc(sizeof(*noeud));
	tab = ft_strsplit((*liste)->content, '-');
	noeud->name_left = ft_strdup(tab[0]);
	noeud->name_right = ft_strdup(tab[1]);
	ft_strdel(tab);
	return (noeud);
}

int		parse_noeud(t_list **liste, t_map *map)
{
	int	i;

	i = 0;
	while (ft_isalnum(((char *)((*liste)->content))[i]) == 1 && ((char *)((*liste)->content))[i])
		i++;
	if (((char *)((*liste)->content))[i] != ' ' && ((char *)((*liste)->content))[i] && ((char *)((*liste)->content))[i] == '-')
		i++;
	while (ft_isalnum(((char *)((*liste)->content))[i]) == 1 && ((char *)((*liste)->content))[i])
		i++;
	if (((char *)((*liste)->content))[i] == '\0')
	{
		ft_lstappend(&map->noeuds, ft_lstnew(struct_noeud(liste), sizeof(t_noeud)));
		return (TRUE);
	}
	return (FALSE);
}

t_room		*struct_room(int type, t_list **liste)
{
	char	**tab;
	t_room	*room;

	room = (t_room*)malloc(sizeof(*room));
	tab = ft_strsplit((*liste)->content, ' ');
	room->name = ft_strdup(tab[0]);
	room->x = ft_atoi(tab[1]);
	room->y = ft_atoi(tab[2]);
	room->type_room = type;
	ft_strdel(tab);
	return (room);
}

int		parse_cmd(t_list **liste, t_map *map)
{
	if (ft_strncmp((*liste)->content, "##", 2) == TRUE)
	{
		if (ft_strcmp((*liste)->content, "##start") == TRUE)
		{
			(*liste) = (*liste)->next;
			if (parse_name_room(liste) == FALSE)
				return (FALSE);
			ft_lstappend(&map->rooms, ft_lstnew(struct_room(3, liste), sizeof(t_room)));
		}
		else if (ft_strcmp((*liste)->content, "##end") == TRUE)
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

int		parse_name_room(t_list **liste)
{
	int	i;

	i = 0;
	if (((char *)((*liste)->content))[0] == 'L' || ((char *)((*liste)->content))[0] == '#')
		return (FALSE);
	while (ft_isalnum(((char *)((*liste)->content))[i]) == 1 && ((char *)((*liste)->content))[i])
		i++;
	if (((char *)((*liste)->content))[i] == ' ' && ((char *)((*liste)->content))[i] && ((char *)((*liste)->content))[i] != '-')
		i++;
	while (ft_isdigit(((char *)((*liste)->content))[i]) == 1 && ((char *)((*liste)->content))[i])
		i++;
	if (((char *)((*liste)->content))[i] == ' ' && ((char *)((*liste)->content))[i])
		i++;
	while (ft_isdigit(((char *)((*liste)->content))[i]) == 1 && ((char *)((*liste)->content))[i])
		i++;
	if (((char *)((*liste)->content))[i] == '\0')
		return (TRUE);
	return (FALSE);
}
