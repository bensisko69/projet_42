/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/28 16:00:45 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/10/28 16:41:59 by lrenoud-         ###   ########.fr       */
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

int		parse_com(t_liste **liste)
{
	if((*liste)->str[0] == '#' && (*liste)->str[1] != '#')
	{
		(*liste)->type = 5;
		return (TRUE);
	}
	return (FALSE);
}

int		parse_nbr(t_liste **liste)
{
	int	i;

	i = 0;
	while (ft_isdigit((int)(*liste)->str[i]) == 1)
		i++;
	if ((*liste)->str[i] == '\0')
	{
		(*liste)->type = 1;
		(*liste) = (*liste)->next;
		return (TRUE);
	}
	return (FALSE);
}

int		parse_room(t_liste **liste)
{
	while (parse_com(liste) == TRUE)
		(*liste) = (*liste)->next;
	return (TRUE);
}

int		parse_exp(t_liste **liste)
{
	while ((*liste)->start != 1)
		(*liste) = (*liste)->next;
	while (parse_com(liste) == TRUE)
		(*liste) = (*liste)->next;
	if (parse_nbr(liste) == TRUE)
	{
		if (parse_room(liste) == TRUE)
			return (TRUE);
	}
	return (TRUE);
}

int		parse(t_liste **liste)
{
	if (parse_exp(liste) == TRUE)
		return (TRUE);
	return (FALSE);
}