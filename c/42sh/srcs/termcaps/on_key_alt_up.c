/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_key_alt_up.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 15:30:22 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/27 15:32:45 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

int			on_key_alt_up(t_context *context, t_line_edit *line_edit)
{
	UNUSED(context);
	UNUSED(line_edit);
	return (READ_CONTINUE);
}
