/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@stduent.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 14:30:51 by lrenoud-          #+#    #+#             */
/*   Updated: 2013/11/30 16:46:52 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"


char	ft_type(t_stat *cp)
{
	if (cp->st_mode & S_IFIFO)
		return ('p');
	else if (cp->st_mode & S_IFCHR)
		return ('c');
	else if (cp->st_mode & S_IFDIR)
		return ('d');
	else if (cp->st_mode & S_IFBLK)
		return ('b');
	else if (cp->st_mode & S_IFREG)
		return ('-');
	else if (cp->st_mode & S_IFLNK)
		return ('l');
	else if (cp->st_mode & S_IFSOCK)
		return ('s');
	else if (cp->st_mode & S_IFWHT)
		return ('w');
	return ('?');
}

char		*ft_permission(t_stat *cp)
{
	char	*str;

	str = ft_strnew(11);
	if (str)
	{
		str[0] = ft_type(cp);
		str[1] = (cp->st_mode & S_IRUSR ? 'r' : '-');
		str[2] = (cp->st_mode & S_IWUSR ? 'w' : '-');
		str[3] = (cp->st_mode & S_IXUSR ? 'x' : '-');
		str[4] = (cp->st_mode & S_IRGRP ? 'r' : '-');
		str[5] = (cp->st_mode & S_IWGRP ? 'w' : '-');
		str[6] = (cp->st_mode & S_IXGRP ? 'x' : '-');
		str[7] = (cp->st_mode & S_IROTH ? 'r' : '-');
		str[8] = (cp->st_mode & S_IWOTH ? 'w' : '-');
		str[9] = (cp->st_mode & S_IXOTH ? 'x' : '-');
		str[10] = ' ';
	}
	return (str);
}
