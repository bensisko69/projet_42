/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_a.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@stduent.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 12:35:55 by lrenoud-          #+#    #+#             */
/*   Updated: 2013/11/29 12:56:00 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	ft_a(void)
{
	struct dirent *file;
	t_link			*list;

	DIR *rep = 0;
	rep = opendir(".");
	if (rep == 0)
	{
		perror ("Error ");
		return (0);
	}
	while ((file = readdir(rep)) != 0)
	{
		ft_insert(&list, file->d_name, &ft_strcmp);
	}
	if (closedir(rep) == -1)
		return (-1);
	while (list != 0)
	{
		ft_putendl(list->element);
		list = list->next;
	}
	return(0);
}
