/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/29 13:46:24 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/12/04 13:37:51 by lrenoud-         ###   ########.fr       */
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

t_noeud		*struct_noeud(t_list **liste)
{
	char	**tab;
	t_noeud	*noeud;

	noeud = (t_noeud*)malloc(sizeof(*noeud));
	tab = ft_strsplit((*liste)->content, '-');
	noeud->name_left = ft_strdup(tab[0]);
	noeud->name_right = ft_strdup(tab[1]);
	free_tab(tab);
	return (noeud);
}

int		parse_noeud(t_list **liste, t_map *map)
{
	int	i;
	t_noeud	*tmp;

	i = 0;
	if ((*liste))
	{
		while (ft_isalnum(((char *)((*liste)->content))[i]) == 1 &&
			((char *)((*liste)->content))[i])
			i++;
		if (((char *)((*liste)->content))[i] != ' '
			&& ((char *)((*liste)->content))[i]
			&& ((char *)((*liste)->content))[i] == '-')
			i++;
		while (ft_isalnum(((char *)((*liste)->content))[i]) == 1
			&& ((char *)((*liste)->content))[i])
			i++;
		if (((char *)((*liste)->content))[i] == '\0')
		{
			tmp = struct_noeud(liste);
			ft_lstappend(&map->noeuds, ft_lstnew(tmp, sizeof(t_noeud)));
			free(tmp);
			return (TRUE);
		}
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
	free_tab(tab);
	return (room);
}

t_room		*struct_cmd(int type, t_list **liste)
{
	t_room	*room;

	room = (t_room*)malloc(sizeof(*room));
	room->name = ft_strdup((*liste)->content);
	room->x = 0;
	room->y = 0;
	room->type_room = type;
	return (room);
}

int		parse_cmd(t_list **liste, t_map *map)
{
	t_room		*tmp;

	tmp = NULL;
	if ((*liste) && ft_strncmp((*liste)->content, "##", 2) == TRUE)
	{
		if (ft_strcmp((*liste)->content, "##start") == TRUE)
		{
			tmp = struct_cmd(3, liste);
			ft_lstappend(&map->rooms, ft_lstnew(tmp, sizeof(t_room)));
			*liste = (*liste)->next;
			free(tmp);
		}
		else if (ft_strcmp((*liste)->content, "##end") == TRUE)
		{
			tmp = struct_cmd(4, liste);
			ft_lstappend(&map->rooms, ft_lstnew(tmp,
				sizeof(t_room)));
			*liste = (*liste)->next;
			free(tmp);
		}
		return (TRUE);
	}
	return (2);
}

int		parse_name_room(t_list **liste, t_map *map)
{
	int	i;

	i = 0;
	if ((*liste))
	{
		if (parse_cmd(liste, map) == FALSE)
			return (FALSE);
		if (((char *)((*liste)->content))[0] == 'L'
			|| ((char *)((*liste)->content))[0] == '#')
			return (FALSE);
		while (ft_isalnum(((char *)((*liste)->content))[i]) == 1
			&& ((char *)((*liste)->content))[i])
			i++;
		if (((char *)((*liste)->content))[i] == ' '
			&& ((char *)((*liste)->content))[i]
			&& ((char *)((*liste)->content))[i] != '-')
			i++;
		else
			return (FALSE);
		while (ft_isdigit(((char *)((*liste)->content))[i]) == 1
			&& ((char *)((*liste)->content))[i])
			i++;
		if (((char *)((*liste)->content))[i] == ' '
			&& ((char *)((*liste)->content))[i])
			i++;
		else
			return (FALSE);
		while (ft_isdigit(((char *)((*liste)->content))[i]) == 1
			&& ((char *)((*liste)->content))[i])
			i++;
		if (((char *)((*liste)->content))[i] == '\0')
			return (TRUE);
	}
	return (FALSE);
}
