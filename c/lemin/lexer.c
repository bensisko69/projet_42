/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/29 14:17:13 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/10/30 16:38:22 by lrenoud-         ###   ########.fr       */
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

int			cmp(t_liste *liste)
{
	char	*str;
	t_liste	*tmp;
	int		size;
	int		r;

	r = 0;
	size = 0;
	tmp = liste;
	while (liste->next->type != 6)
	{
		str = liste->str;
		tmp = liste->next;
		if (tmp->type == 4 || tmp->type == 3)
			tmp = tmp->next;
		while ((r = ft_strncmp(str, tmp->str, len(str))) != 0 && tmp->type != 6)
			tmp = tmp->next;
		if (r == 0)
		{
			ft_error(3, str);
			return (FALSE);
		}
		liste = liste->next;
	}
	return (TRUE);
}

int			check_name_room(t_liste **liste)
{
	while ((*liste)->type != 2)
		(*liste) = (*liste)->next;
	if ((*liste)->type == 3 || (*liste)->type == 4)
		(*liste) = (*liste)->next;
	if (cmp(*liste) == FALSE)
		return (FALSE);
	return (TRUE);
}

// int			check_cmd(t_liste *liste)
// {
	
// }

int			lexer(t_liste **liste)
{
	while ((*liste)->start != 1)
		(*liste) = (*liste)->next;
	if (check_name_room(liste) == FALSE)
		return (FALSE);
	// if (check_cmd(liste) == FALSE)
		// return (FALSE);
	return (TRUE);
}
