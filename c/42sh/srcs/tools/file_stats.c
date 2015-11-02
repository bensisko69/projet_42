/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_stats.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 14:17:58 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/03 14:31:17 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>

#include "tools.h"

static int	is_file_type(const char *path, int type)
{
	t_stat	file_stat;

	if (!stat(path, &file_stat))
		return ((file_stat.st_mode & type) == type);
	return (0);
}

int			is_file(const char *path)
{
	return (is_file_type(path, S_IFREG));
}

int			is_dir(const char *path)
{
	return (is_file_type(path, S_IFDIR));
}
