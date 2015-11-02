/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_key_ctrl_u.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 17:37:11 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/18 17:42:25 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

int			on_key_ctrl_u(t_context *context, t_line_edit *line_edit)
{
	UNUSED(context);
	term_command_n(CAP_CURSOR_LEFT, line_edit->pos);
	line_edit->pos = 0;
	line_remove(line_edit, line_edit->len);
	return (READ_CONTINUE);
}
