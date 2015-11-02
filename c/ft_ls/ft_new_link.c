/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_link.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@stduent.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 16:47:37 by lrenoud-          #+#    #+#             */
/*   Updated: 2013/11/29 17:37:54 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_link	*ft_new_link(const char *str)
{
	t_link	*newlink;

	newlink = malloc(sizeof(t_link));
	if (newlink != 0)
	{
		newlink->element = ft_strdup(str);
		newlink->next = 0;
	}
	return (newlink);
}
