/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 19:11:24 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/11/10 19:13:29 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_push(char *line, t_list **list)
{
	t_list	*new_link;

	new_link = create_ellem(line);
	if ((*list) == NULL)
		*list = new_link;
	else
	{
		while((*list)->next->start != 1)
			*list = (*list)->next;
		new_link->next = (*list)->next;
		new_link->previous = *list;
		(*list)->next = new_link;
		new_link->next->previous = new_link;
	}
}