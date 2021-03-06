/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_count.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 09:17:53 by juschaef          #+#    #+#             */
/*   Updated: 2015/01/07 18:25:55 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

size_t		lst_count(t_lst *lst, void *(*f)(void *))
{
	int			len;
	t_lst_elem	*elem;

	len = 0;
	elem = lst->elems;
	while (elem)
	{
		if (f(elem->data))
			len++;
		elem = elem->next;
	}
	return (len);
}
