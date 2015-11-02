/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@stduent.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 19:39:14 by lrenoud-          #+#    #+#             */
/*   Updated: 2013/11/30 21:53:36 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_insert(t_link **list, const char *str, t_cmp cmp)
{
	t_link	*i;
	t_link	*temp;

	if (*list == 0)
		*list = ft_new_link(str);
	else if (cmp(str, (*list)->element) < 0)
			ft_add_start(list, str);
	else
	{
		i = *list;
		while (i->next != 0)
		{
			if (cmp(str, i->next->element) < 0)
			{
				temp = ft_new_link(str);
				temp->next = i->next;
				i->next = temp;
				return ;
			}
			i = i->next;
		}
		i->next = ft_new_link(str);
	}
}
