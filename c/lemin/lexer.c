/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/29 14:17:13 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/10/29 15:38:36 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		cmp(t_liste *liste)
{
	char	*str;
	t_liste	*tmp;

	while (liste->type == 2 && liste->type == 3 && liste->type == 4)
	{
		ft_putendl(liste->str);
		ft_putnbr(liste->type);
		if (liste->type == 5)
			liste = liste->next;
		str = liste->str;
		tmp = liste->next;
		while (ft_strcmp(str, tmp->str) == 0)
			tmp = tmp->next;
		liste = liste->next;
	}
	if (tmp->type == 6)
		return (TRUE);
	return (FALSE);
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
