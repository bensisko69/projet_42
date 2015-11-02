/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_l.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@stduent.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 16:54:19 by lrenoud-          #+#    #+#             */
/*   Updated: 2013/11/30 18:14:00 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char	ft_gr(gid_t grp)
{


}







int	ft_l(void)
{
	struct dirent *file;
	struct stat file_stat;

	DIR *rep = 0;
	rep = opendir(".");
	if (rep == 0)
	{
		perror ("Error ");
		exit (0);
	}
	while ((file = readdir(rep)) != 0)
	{
		if (file->d_name[0] != '.')
		{
			stat(file->d_name, &file_stat);
			ft_permission(&file_stat);
			ft_putchar('\n');
		}
	}
	if (closedir(rep) == -1)
		exit (-1);
	return(0);
}
