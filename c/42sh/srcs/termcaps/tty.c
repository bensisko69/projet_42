/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tty.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 18:50:21 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/23 00:47:29 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

#include "termcaps.h"

static int		open_tty(void)
{
	char		*tty_file_name;
	int			fd;

	if (isatty(STDIN))
	{
		tty_file_name = ttyname(STDIN);
		fd = open(tty_file_name, O_RDWR);
		if (fd != -1 && isatty(fd))
			return (fd);
	}
	shell_error(ERR_NO_TTY, 0);
	shell_exit(get_context(), EXIT_ERROR);
	return (-1);
}

int				tty_fd(void)
{
	static int	fd = -1;

	if (fd == -1)
		fd = (isatty(STDOUT) ? STDOUT : open_tty());
	return (fd);
}

void			close_tty(void)
{
	close(tty_fd());
}
