/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_key_ctrl_e.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 17:16:47 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/18 17:19:18 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

int			on_key_ctrl_e(t_context *context, t_line_edit *line_edit)
{
	UNUSED(context);
	term_command_n(CAP_CURSOR_RIGHT, line_edit->len - line_edit->pos);
	line_edit->pos = line_edit->len;
	return (READ_CONTINUE);
}
