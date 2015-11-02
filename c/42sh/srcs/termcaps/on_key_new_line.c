/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_key_new_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 23:34:51 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/27 16:01:31 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

int			on_key_new_line(t_context *context, t_line_edit *line_edit)
{
	UNUSED(line_edit);
	context->history_ptr = 0;
	return (READ_STOP);
}
