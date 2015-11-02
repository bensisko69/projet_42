/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_key_ctrl_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 17:16:46 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/18 17:19:16 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

int			on_key_ctrl_a(t_context *context, t_line_edit *line_edit)
{
	UNUSED(context);
	term_command_n(CAP_CURSOR_LEFT, line_edit->pos);
	line_edit->pos = 0;
	return (READ_CONTINUE);
}
