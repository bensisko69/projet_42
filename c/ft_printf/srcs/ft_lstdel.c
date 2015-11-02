/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 15:01:22 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/01/19 15:01:24 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*temp;
	t_list	*temp2;

	if (alst && *alst)
	{
		temp = (*alst);
		while (temp)
		{
			del(temp->content, temp->content_size);
			temp2 = temp;
			temp = temp->next;
			free(temp2);
		}
	}
	(*alst) = NULL;
}
