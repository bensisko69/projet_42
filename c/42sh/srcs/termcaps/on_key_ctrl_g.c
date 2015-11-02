/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_key_ctrl_g.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 18:05:37 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/18 19:02:29 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

int			on_key_ctrl_g(t_context *context, t_line_edit *line_edit)
{
	WRITE(tty_fd(), "\a");
	return (on_key_ctrl_c(context, line_edit));
}
