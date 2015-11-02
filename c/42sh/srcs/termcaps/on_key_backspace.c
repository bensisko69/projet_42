/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_key_backspace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 23:40:20 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/18 01:30:44 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

int			on_key_backspace(t_context *context, t_line_edit *line_edit)
{
	UNUSED(context);
	if (line_edit->pos)
	{
		--line_edit->pos;
		term_command(CAP_CURSOR_LEFT);
		line_remove(line_edit, 1);
	}
	return (READ_CONTINUE);
}
