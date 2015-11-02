/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_key_ctrl_k.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 16:26:11 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/18 16:29:16 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

int			on_key_ctrl_k(t_context *context, t_line_edit *line_edit)
{
	UNUSED(context);
	line_remove(line_edit, line_edit->len - line_edit->pos);
	return (READ_CONTINUE);
}
