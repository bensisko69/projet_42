/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 19:11:24 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/11/19 17:19:48 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

static t_list	*create_ellem(char *line)
{
	t_list	*new_link;

	new_link = (t_list *)malloc(sizeof(*new_link));
	if (new_link)
	{
		new_link->str = line;
		new_link->next = new_link;
		new_link->prev = new_link;
	}
	return (new_link);
}

void			ft_list_push(char *line, t_list **list)
{
	t_list	*new_link;

	(void)g_op_tab;
	new_link = create_ellem(line);
	if ((*list) == NULL)
	{
		new_link->start = 1;
		*list = new_link;
	}
	else
	{
		while ((*list)->next->start != 1)
			*list = (*list)->next;
		new_link->start = 0;
		new_link->next = (*list)->next;
		new_link->prev = *list;
		(*list)->next = new_link;
		new_link->next->prev = new_link;
	}
}
