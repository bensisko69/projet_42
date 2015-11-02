/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_key_down_arrow.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 15:29:36 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/27 16:22:30 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "termcaps.h"

int			on_key_down_arrow(t_context *context, t_line_edit *line_edit)
{
	char	*str;

	on_key_ctrl_u(context, line_edit);
	if (context->history && context->history_ptr)
	{
		if (context->history_ptr != context->history->previous)
			context->history_ptr = context->history_ptr->next;
		else
			context->history_ptr = 0;
		if (context->history_ptr)
		{
			str = ((t_history *)(context->history_ptr->content))->entry;
			line_insert(line_edit, str, ft_strlen(str));
		}
	}
	return (READ_CONTINUE);
}
