/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/28 16:00:45 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/11/23 17:46:05 by lrenoud-         ###   ########.fr       */
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

int		parse_nbr(t_liste **liste)
{
	int	i;

	i = 0;
	while (ft_isdigit((int)(*liste)->str[i]) == 1)
		i++;
	if ((*liste)->str[i] == '\0')
	{
		(*liste)->type = 1;
		(*liste)->nbr_ants = ft_atoi((*liste)->str);
		(*liste) = (*liste)->next;
		return (TRUE);
	}
	return (FALSE);
}

int		parse_tube(t_liste **liste)
{
	while (parse_com(liste) == TRUE)
		(*liste) = (*liste)->next;
	while (parse_noeud(liste) == TRUE)
		(*liste) = (*liste)->next;
	return (TRUE);
}

int		parse_room(t_liste **liste)
{
	while (parse_com(liste) == TRUE)
		(*liste) = (*liste)->next;
	if (parse_cmd(liste) == FALSE)
		return (FALSE);
	else if (parse_name_room(liste) == FALSE)
		return (FALSE);
	return (TRUE);
}

int		parse_exp(t_liste **liste)
{
	while (parse_com(liste) == TRUE)
		(*liste) = (*liste)->next;
	if (parse_nbr(liste) == FALSE)
		return (FALSE);
	while (parse_room(liste) == TRUE || parse_cmd(liste) == TRUE)
	{
		while (parse_com(liste) == TRUE)
			(*liste) = (*liste)->next;
		(*liste) = (*liste)->next;
	}
	if (parse_tube(liste) == FALSE)
		return (FALSE);
	if (check_list(liste) == FALSE)
		return (FALSE);
	return (TRUE);
}

static int		list(t_liste **liste)
{
	int	nbr;
	int cmd_start;
	int	cmd_end;
	int	rooms;
	int	tubes;

	nbr = 0;
	cmd_start = 0;
	cmd_end = 0;
	rooms = 0;
	tubes = 0;
	start_liste(liste);
	while ((*liste)->type == 5)
		(*liste) = (*liste)->next;
	if ((*liste)->type == 1)
		nbr = 1;
	(*liste) = (*liste)->next;
	while ((*liste)->start != 1)
	{
		if ((*liste)->type == 2)
			rooms = 1;
		else if ((*liste)->type == 3)
			cmd_start = 1;
		else if ((*liste)->type == 4)
			cmd_end = 1;
		else if ((*liste)->type == 6)
			tubes = 1;
		(*liste) = (*liste)->next;
	}
	if (nbr == 1 && cmd_start == 1 && cmd_end == 1 && rooms == 1 && tubes == 1)
		return (TRUE);
	return (FALSE);
}

int		parse(t_liste **liste)
{
	start_liste(liste);
	if (parse_exp(liste) ==  FALSE)
		return (FALSE);
	else if (list(liste) == FALSE)
		return (FALSE);
	return (TRUE);
}
