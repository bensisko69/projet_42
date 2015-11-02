/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_key_up_arrow.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 15:29:31 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/27 15:57:15 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "termcaps.h"

int			on_key_up_arrow(t_context *context, t_line_edit *line_edit)
{
	char	*str;

	if (context->history)
	{
		if (!context->history_ptr)
			context->history_ptr = context->history->previous;
		else if (context->history_ptr != context->history)
			context->history_ptr = context->history_ptr->previous;
		on_key_ctrl_u(context, line_edit);
		str = ((t_history *)(context->history_ptr->content))->entry;
		line_insert(line_edit, str, ft_strlen(str));
	}
	return (READ_CONTINUE);
}
