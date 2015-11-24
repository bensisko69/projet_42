/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:14:21 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/11/24 15:31:45 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstappend(t_list **alst, t_list *new_element)
{
	t_list	*it;

	if (!*alst)
		*alst = new_element;
	else
	{
		it = *alst;
		while (it->next)
			it = it->next;
		it->next = new_element;
	}
}
