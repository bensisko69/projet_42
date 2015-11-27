/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 14:25:13 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/11/27 16:06:28 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(const void *content, size_t content_size)
{
	t_list  *element;

	element = (t_list *)malloc(sizeof(t_list));
	if (element)
	{
		element->content_size = (content ? content_size : 0);
		element->content = (content ? malloc(content_size) : 0);
		if (element->content)
			ft_memcpy(element->content, content, content_size);
		element->next = 0;
	}
	return (element);
}
