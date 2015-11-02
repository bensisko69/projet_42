/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 20:32:13 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/14 20:41:57 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

#include "interpreter.h"

int			exec_file(t_context *context, const char *file_name)
{
	int		fd;
	int		ret;
	char	*line;

	ret = 1;
	fd = open_file(file_name, O_RDONLY, 0);
	if (fd != -1)
	{
		while (get_next_line(fd, &line) == 1)
		{
			ret = exec_line(context, line);
			free(line);
		}
		UNUSED(close(fd));
	}
	return (ret);
}
