/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_key_right_arrow.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 00:26:16 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/18 00:55:33 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

int			on_key_right_arrow(t_context *context, t_line_edit *line_edit)
{
	UNUSED(context);
	UNUSED(line_edit);
	if (line_edit->pos < line_edit->len)
	{
		++line_edit->pos;
		term_command(CAP_CURSOR_RIGHT);
	}
	return (READ_CONTINUE);
}
