/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 22:28:45 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/27 13:06:45 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

char			*read_line(t_context *context, int fd)
{
	char		key[KEY_BUFF_SIZE + 1];
	ssize_t		read_size;
	t_line_edit	line_edit;

	ft_bzero(key, sizeof(key));
	ft_bzero(&line_edit, sizeof(t_line_edit));
	term_set_raw_mode(context);
	while ((read_size = read(fd, &key, KEY_BUFF_SIZE)) > 0)
	{
		if (handle_key(context, &line_edit, key, read_size) == READ_STOP)
			break ;
		ft_bzero(key, sizeof(key));
	}
	term_restore_mode(context);
	WRITE(tty_fd(), "\n");
	return (ft_strdup(line_edit.line));
}
