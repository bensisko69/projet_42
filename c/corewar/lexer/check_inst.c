/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/19 18:45:20 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/11/21 18:39:41 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

static int	check_line_inst(t_list **list)
{
	int	i;

	i = 0;
	while ((*list)->str[i] && (*list)->str[i] != ' ' && (*list)->str[i] != '\t')
		i++;
		return (TRUE);
}

int			check_inst(t_list **list)
{
	while ((*list)->start != 1)
		(*list) = (*list)->next;
	if ((*list)->type == 4)
	{
		if (check_line_inst(list) == TRUE)
			return (TRUE);
	}
	(*list) = (*list)->next;
	while ((*list)->start != 1)
	{
		if ((*list)->type == 4)
		{
			if (check_line_inst(list) == TRUE)
				return (TRUE);
		}
		(*list) = (*list)->next;
	}
	return (TRUE);
}
