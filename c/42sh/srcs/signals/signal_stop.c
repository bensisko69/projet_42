/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_stop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 15:35:24 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/19 20:19:27 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "interpreter.h"
#include "termcaps.h"

void			on_signal_stop(int sig)
{
	t_context	*context;

	UNUSED(sig);
	context = get_context();
	if (context->busy_job)
	{
		context->do_susp = 1;
		WRITE(tty_fd(), "\n");
	}
}
