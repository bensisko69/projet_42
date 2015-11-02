/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_cmt_or_name.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/20 15:30:48 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/11/21 18:32:41 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

static void	check_tp(int type, int *nb_name, int *nb_cmt)
{
	if (type == 1)
		(*nb_name) += 1;
	else if (type == 2)
		(*nb_cmt) += 1;
}

int			check_nb_cmt_or_name(t_list **list)
{
	int	nb_name;
	int	nb_cmt;

	nb_cmt = 0;
	nb_name = 0;
	while ((*list)->start != 1)
		(*list) = (*list)->next;
	check_tp((*list)->type, &nb_name, &nb_cmt);
	(*list) = (*list)->next;
	while ((*list)->start != 1)
	{
		check_tp((*list)->type, &nb_name, &nb_cmt);
		(*list) = (*list)->next;
	}
	if (nb_cmt > 1)
	{
		ft_error_lexer(0);
		return (FALSE);
	}
	else if (nb_name > 1)
	{
		ft_error_lexer(1);
		return (FALSE);
	}
	return (TRUE);
}
