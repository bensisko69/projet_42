/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_key_alt_down.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 15:30:20 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/27 15:30:44 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

int			on_key_alt_down(t_context *context, t_line_edit *line_edit)
{
	UNUSED(context);
	UNUSED(line_edit);
	return (READ_CONTINUE);
}
