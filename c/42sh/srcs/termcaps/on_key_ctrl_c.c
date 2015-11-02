/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_key_ctrl_c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 18:14:33 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/18 18:34:34 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"
#include "prompt.h"

int			on_key_ctrl_c(t_context *context, t_line_edit *line_edit)
{
	context->last_status = 1;
	line_edit->pos = 0;
	line_remove(line_edit, line_edit->len);
	return (READ_STOP);
}
