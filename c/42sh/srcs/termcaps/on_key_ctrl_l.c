/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_key_ctrl_l.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 15:46:37 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/18 18:57:41 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"
#include "prompt.h"

int			on_key_ctrl_l(t_context *context, t_line_edit *line_edit)
{
	term_command(CAP_CLEAR_SCREEN);
	show_prompt(context);
	term_command(CAP_INSERT_MODE);
	write(tty_fd(), line_edit->line, line_edit->len);
	term_command(CAP_END_INSERT);
	return (READ_CONTINUE);
}
