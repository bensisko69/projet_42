/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@stduent.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 12:35:47 by lrenoud-          #+#    #+#             */
/*   Updated: 2013/11/29 12:56:06 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	ft_ls(void)
{
	struct dirent	*file;
	t_link			*list;

	list = 0;
	DIR *rep = 0;
	rep =  opendir(".");
	if (rep == 0)
	{
		perror ("Error ");
		exit(0);
	}
	while ((file = readdir(rep)) != 0)
	{
		if (file->d_name[0] != '.')
			ft_insert(&list, file->d_name, &ft_strcmp);
	}
	if (closedir(rep) == -1)
		exit(-1);
	while (list != 0)
	{
		ft_putendl(list->element);
		list = list->next;
	}
	return (0);
}
