/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/28 15:54:31 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/10/28 16:30:32 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_liste		*create_ellem(char *line)
{
	t_liste	*new_link;

	new_link = (t_liste *)malloc(sizeof(*new_link));
	new_link->type = 0;
	new_link->str = ft_strdup((const char*)line);
	new_link->next = new_link;
	new_link->previous = new_link;
	return (new_link);
}

void		ft_liste_push(char *line, t_liste **list)
{
	t_liste	*new_link;

	new_link = create_ellem(line);
	if ((*list) == NULL)
	{
		new_link->start = 1;
		*list = new_link;
	}
	else if ((*list) != NULL)
	{
		new_link->start = 0;
		while ((*list)->next->start != 1)
			*list = (*list)->next;
		new_link->next = (*list)->next;
		new_link->previous = *list;
		(*list)->next = new_link;
		new_link->next->previous = new_link;
	}
}

void		print_liste(t_liste *list)
{
	if (list == NULL)
	{
		ft_putendl("NULL");
		exit(0);
	}
	while (list->start != 1)
		list = list->next;
	while (list->next->start != 1)
	{
		ft_putnbr(list->type);
		// ft_putnbr(list->start);
		ft_putstr(list->str);
		write(1, "\n", 1);
		list = list->next;
	}
	ft_putnbr(list->type);
	// ft_putnbr(list->start);
	ft_putstr(list->str);
	write(1, "\n", 1);
}