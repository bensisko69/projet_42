/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 14:25:13 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/01/19 14:25:14 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*newlink;

	(void)content_size;
	newlink = (t_list*)malloc(sizeof(t_list));
	if (newlink == NULL)
		return (NULL);
	newlink->content = (void*)content;
	newlink->content_size = 0;
	newlink->next = NULL;
	return (newlink);
}
