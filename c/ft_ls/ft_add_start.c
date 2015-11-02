/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@stduent.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 17:38:45 by lrenoud-          #+#    #+#             */
/*   Updated: 2013/11/29 17:38:59 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_add_start(t_link **list,const char *str)
{
	t_link	*tmp_list;

	tmp_list = ft_new_link(str);
	tmp_list->next = *list;
	*list = tmp_list;
}
