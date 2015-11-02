/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/25 21:49:18 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/09/25 23:41:49 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	free(void *ptr)
{
	t_size	*list;

	list = ptr - sizeof(t_size *);
	if (ptr != NULL)
	{
		if (munmap(ptr, sizeof(ptr - sizeof(t_size *)) != -1))
			list->free = 1;
	}
}
