/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 17:33:31 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/01/19 17:33:32 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_push_back(t_list **list, t_list *newlink)
{
	t_list	*it;

	if (!(*list))
		(*list) = newlink;
	else
	{
		it = (*list);
		while (it->next != NULL)
			it = it->next;
		it->next = newlink;
	}
}
