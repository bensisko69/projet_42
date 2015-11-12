/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/29 13:46:24 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/11/12 19:00:09 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	struct_noeud(t_liste **liste)
{
	char	**tab;

	tab = ft_strsplit((*liste)->str, '-');
	(*liste)->noeud.name_left = tab[0];
	(*liste)->noeud.name_right = tab[1];
}

int		parse_noeud(t_liste **liste)
{
	int	i;

	i = 0;
	while (parse_com(liste) == TRUE)
		(*liste) = (*liste)->next;
	if ((*liste)->str[0] == 'L' || (*liste)->str[0] == '#')
		return (FALSE);
	while (ft_isalnum((int)(*liste)->str[i]) == 1 && (*liste)->str[i])
		i++;
	if ((*liste)->str[i] != ' ' && (*liste)->str[i] && (*liste)->str[i] == '-')
		i++;
	while (ft_isalnum((int)(*liste)->str[i]) == 1 && (*liste)->str[i])
		i++;
	if ((*liste)->str[i] == '\0' && (*liste)->type != 1)
	{
		(*liste)->type = 6;
		struct_noeud(liste);
		return (TRUE);
	}
	return (FALSE);
}

int		parse_cmd(t_liste **liste)
{
	if (ft_strncmp((*liste)->str, "##", 2) == TRUE)
	{
		if (ft_strcmp((*liste)->str, "##start") == TRUE)
		{
			(*liste)->type = 3;
			(*liste) = (*liste)->next;
			while (parse_com(liste) == TRUE)
				(*liste) = (*liste)->next;
			if (parse_name_room(liste) == FALSE)
				return (FALSE);
			(*liste)->room.type_room = 1;
		}
		else if (ft_strcmp((*liste)->str, "##end") == TRUE)
		{
			(*liste)->type = 4;
			(*liste) = (*liste)->next;
			while (parse_com(liste) == TRUE)
				(*liste) = (*liste)->next;
			if (parse_name_room(liste) == FALSE)
				return (FALSE);
			(*liste)->room.type_room = 2;
		}
		else
			return (FALSE);
		(*liste) = (*liste)->next;
		return (TRUE);
	}
	return (2);
}


static void	struct_room(t_liste **liste)
{
	char	**tab;

	tab = ft_strsplit((*liste)->str, ' ');
	(*liste)->room.name = tab[0];
	(*liste)->room.x = ft_atoi(tab[1]);
	(*liste)->room.y = ft_atoi(tab[2]);
	(*liste)->room.type_room = 0;
}

int		parse_name_room(t_liste **liste)
{
	int	i;

	i = 0;
	while (parse_com(liste) == TRUE)
		(*liste) = (*liste)->next;
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
	{
		(*liste)->type = 2;
		struct_room(liste);
			return (TRUE);
	}
	return (FALSE);
}

int		parse_com(t_liste **liste)
{
	if ((*liste)->str[0] == '#' && (*liste)->str[1] != '#')
	{
		(*liste)->type = 5;
		return (TRUE);
	}
	return (FALSE);
}
