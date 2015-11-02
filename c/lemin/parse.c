/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/28 16:00:45 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/11/02 18:53:12 by lrenoud-         ###   ########.fr       */
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

int		parse_room(t_liste **liste)
{
	while (parse_com(liste) == TRUE)
		(*liste) = (*liste)->next;
	if (parse_cmd(liste) == TRUE)
		(*liste) = (*liste)->next;
	while (parse_name_room(liste) == TRUE)
	{
		(*liste) = (*liste)->next;
		if (parse_cmd(liste) == TRUE)
			(*liste) = (*liste)->next;
	}
	return (TRUE);
}

int		parse_tube(t_liste **liste)
{
	while (parse_com(liste) == TRUE)
		(*liste) = (*liste)->next;
	while (parse_noeud(liste) == TRUE)
		(*liste) = (*liste)->next;
	return (TRUE);
}

int		parse_exp(t_liste **liste)
{
	while (parse_com(liste) == TRUE)
		(*liste) = (*liste)->next;
	if (parse_nbr(liste) == FALSE)
		return (FALSE);
	if (parse_room(liste) == FALSE)
		return (FALSE);
	if (parse_tube(liste) == FALSE)
		return (FALSE);
	return (TRUE);
}

int		parse(t_liste **liste)
{
	while ((*liste)->start != 1)
		(*liste) = (*liste)->next;
	if (parse_exp(liste) ==  FALSE)
		return (FALSE);
	return (TRUE);
}
