/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_key_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 17:26:31 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/18 17:28:12 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

int			on_key_tab(t_context *context, t_line_edit *line_edit)
{
	UNUSED(context);
	UNUSED(line_edit);
	return (READ_CONTINUE);
}
