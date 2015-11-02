/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@stduent.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 22:47:41 by lrenoud-          #+#    #+#             */
/*   Updated: 2013/11/30 22:49:21 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int revcmp(const char * s1, const char * s2)
{
	return (-ft_strcmp(s1, s2));
}

int	ft_r(void)
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
			ft_insert(&list, file->d_name, &revcmp);
	}
	if (closedir(rep) == -1)
		exit(-1);
	while (list != 0)
	{
		ft_putendl(list->element);
		list = list->next;
	}
	return(0);
}
