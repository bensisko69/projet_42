/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/23 15:38:44 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/09/25 23:43:30 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static void		*insert_struct(void *map, size_t size)
{
	t_size	*list;

	list = (t_size *)map;
	list->free = 0;
	list->size = size;
	list->next = NULL;
	return ((map + sizeof(t_size)));
}

static size_t	large_size(size_t size)
{
	return ((getpagesize() - size) % (getpagesize()));
}

static void		*mapping(size_t size_map, size_t size)
{
	void	*map;

	map = mmap(0, size_map, PROT_READ | PROT_WRITE,
				MAP_ANON | MAP_PRIVATE, -1, 0);
	if (map == (void *)-1)
		return ((void *)0);
	map = insert_struct(map, size);
	return (map);
}

void			*malloc(size_t size)
{
	size_t		page_size;

	page_size = getpagesize();
	if (size <= page_size * SIZE_TINY)
		return (mapping(page_size * SIZE_TINY, size));
	else if (size <= page_size * SIZE_SMALL)
		return (mapping(page_size * SIZE_SMALL, size));
	else
		return (mapping(large_size(size), size));
}
