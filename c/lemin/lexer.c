/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/29 14:17:13 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/10/29 15:25:35 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		cmp(t_liste *liste)
{

	return (TRUE);
}

int		check_name_room(t_liste **liste)
{
	while((*liste)->type != 2 && (*liste)->type != 3 && (*liste)->type != 4)
		(*liste) = (*liste)->next;
	if ((*liste)->type == 3 || (*liste)->type == 4)
		(*liste) = (*liste)->next;
	if (cmp(*liste) == FALSE)
	{
		ft_error(3 , (*liste)->str);
		return (FALSE);
	}
	return (TRUE);
}

int		lexer(t_liste **liste)
{
	while((*liste)->start != 1)
		(*liste) = (*liste)->next;
	if (check_name_room(liste) == FALSE)
		return (FALSE);
	return (TRUE);
}
