/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_key_alt_left.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 17:01:25 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/18 17:05:41 by gudepard         ###   ########.fr       */
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

int			on_key_alt_left(t_context *context, t_line_edit *le)
{
	UNUSED(context);
	while (le->pos && is_white_space(le->line[le->pos - 1]))
		move_left(le);
	while (le->pos && !is_white_space(le->line[le->pos - 1]))
		move_left(le);
	return (READ_CONTINUE);
}
