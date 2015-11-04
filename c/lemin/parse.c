/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/28 16:00:45 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/11/04 17:16:00 by lrenoud-         ###   ########.fr       */
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

int		check_cmd(t_liste **liste)
{
	int	start;
	int	end;

	start = 0;
	end = 0;
	t_liste *tmp;

	tmp = (*liste);

	while (tmp->start != 1)
		tmp = tmp->next;
	if (tmp->type == 3)
		start++;
	else if (tmp->type == 4)
		end++;
	tmp = tmp->next;
	while (tmp->start != 1)
	{
		if (tmp->type == 3)
			start++;
		if (tmp->type == 4)
			end++;
		tmp = tmp->next;
	}
	if (start != 1 || end != 1)
		return (FALSE);
	return (TRUE);
}

int		parse_room(t_liste **liste)
{
	while (parse_com(liste) == TRUE)
		(*liste) = (*liste)->next;
	while (parse_cmd(liste) == TRUE)
		(*liste) = (*liste)->next;
	while (parse_name_room(liste) == TRUE)
	{
		(*liste) = (*liste)->next;
		while (parse_com(liste) == TRUE)
		{
			(*liste) = (*liste)->next;
		}
		if (parse_cmd(liste) == TRUE)
			(*liste) = (*liste)->next;
	ft_putendl((*liste)->str);
	}
	if (check_cmd(liste) == FALSE)
		return (FALSE);
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
