/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_key_alt_right.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 17:01:28 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/18 17:08:41 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

static int	is_white_space(char c)
{
	return (c == ' ' || c == '\t');
}

static void	move_right(t_line_edit *line_edit)
{
	term_command(CAP_CURSOR_RIGHT);
	++line_edit->pos;
}

int			on_key_alt_right(t_context *context, t_line_edit *le)
{
	UNUSED(context);
	while (le->pos < le->len && is_white_space(le->line[le->pos]))
		move_right(le);
	while (le->pos < le->len && !is_white_space(le->line[le->pos]))
		move_right(le);
	return (READ_CONTINUE);
}
