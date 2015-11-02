/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_key_ctrl_d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 00:07:29 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/18 19:02:18 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

int			on_key_ctrl_d(t_context *context, t_line_edit *line_edit)
{
	if (!line_edit->len)
	{
		term_restore_mode(context);
		WRITE(tty_fd(), "\n");
		shell_exit(context, EXIT_SUCCESS);
	}
	if (line_edit->pos < line_edit->len)
		line_remove(line_edit, 1);
	return (READ_CONTINUE);
}
