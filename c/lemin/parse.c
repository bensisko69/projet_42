/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/28 16:00:45 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/11/12 14:47:16 by lrenoud-         ###   ########.fr       */
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
	(*liste) = (*liste)->previous;
	if (parse_tube(liste) == FALSE)
		return (FALSE);
	if (check_list(liste) == FALSE)
		return (FALSE);
	return (TRUE);
}

int		parse(t_liste **liste)
{
	start_liste(liste);
	if (parse_exp(liste) ==  FALSE)
		return (FALSE);
	return (TRUE);
}
