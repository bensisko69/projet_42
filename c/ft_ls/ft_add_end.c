/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_end.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@stduent.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 17:39:12 by lrenoud-          #+#    #+#             */
/*   Updated: 2013/11/29 17:39:20 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_add_end(t_link **list, char *str)
{
	t_link	*tmp_list;

	if (*list == 0)
		*list = ft_new_link(str);
	else
	{
		tmp_list = *list;
		while (tmp_list->next != 0)
			tmp_list = tmp_list->next;
		tmp_list->next = ft_new_link(str);
	}
}
