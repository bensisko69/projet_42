/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/29 14:17:13 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/10/30 16:28:33 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	len(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != ' ')
		i++;
	return (i);
}

int		cmp(t_liste *liste)
{
	char	*str;
	t_liste	*tmp;
	int		size;
	int		ret;

	ret = 0;
	size = 0;
	tmp = liste;
	while (liste->next->type != 6)
	{
		str = liste->str;
		tmp = liste->next;
		if (tmp->type == 4 || tmp->type == 3)
			tmp = tmp->next;
		while ((ret = ft_strncmp(str, tmp->str, len(str))) != 0 && tmp->type != 6)
			tmp = tmp->next;
		if (ret == 0)
		{
			ft_error(3 , str);
			return (FALSE);
		}
		liste = liste->next;
	}
	return (TRUE);
}

int		check_name_room(t_liste **liste)
{
	while((*liste)->type != 2)
		(*liste) = (*liste)->next;
	if ((*liste)->type == 3 || (*liste)->type == 4)
		(*liste) = (*liste)->next;
	if (cmp(*liste) == FALSE)
		return (FALSE);
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
