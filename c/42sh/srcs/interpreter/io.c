/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 19:21:57 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/14 19:46:48 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

#include "interpreter.h"

static void	io_error(const char *file_name, int flags)
{
	if ((flags & O_WRONLY) == O_WRONLY)
		return (shell_error(ERR_DENIED, file_name));
	if (access(file_name, F_OK) == -1)
		return (shell_error(ERR_NO_SUCH_FILE, file_name));
	if ((flags & O_RDONLY) == O_RDONLY && access(file_name, R_OK) == -1)
		return (shell_error(ERR_DENIED, file_name));
	return (shell_error(ERR_UNKNOWN, file_name));
}

int			open_file(const char *file_name, int oflags, mode_t permissions)
{
	int		fd;

	fd = open(file_name, oflags, permissions);
	if (fd == -1)
		io_error(file_name, oflags);
	return (fd);
}
