/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_key_ctrl_w.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 16:07:03 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/18 16:24:16 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

static int	is_white_space(char c)
{
	return (c == ' ' || c == '\t');
}

static void	move_left(t_line_edit *line_edit)
{
	term_command(CAP_CURSOR_LEFT);
	--line_edit->pos;
}

int			on_key_ctrl_w(t_context *context, t_line_edit *le)
{
	size_t	len;

	UNUSED(context);
	len = 0;
	while (le->pos && is_white_space(le->line[le->pos - 1]))
	{
		move_left(le);
		++len;
	}
	while (le->pos && !is_white_space(le->line[le->pos - 1]))
	{
		move_left(le);
		++len;
	}
	line_remove(le, len);
	return (READ_CONTINUE);
}
