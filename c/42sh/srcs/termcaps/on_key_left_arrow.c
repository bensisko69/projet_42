/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_key_left_arrow.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 00:21:26 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/18 00:55:14 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

int			on_key_left_arrow(t_context *context, t_line_edit *line_edit)
{
	UNUSED(context);
	UNUSED(line_edit);
	if (line_edit->pos)
	{
		--line_edit->pos;
		term_command(CAP_CURSOR_LEFT);
	}
	return (READ_CONTINUE);
}
