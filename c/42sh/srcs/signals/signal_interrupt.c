/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_interrupt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/15 17:29:08 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/19 20:11:01 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>

#include "prompt.h"
#include "termcaps.h"

void			on_signal_interrupt(int sig)
{
	t_context	*context;

	UNUSED(sig);
	context = get_context();
	context->last_status = 1;
	WRITE(tty_fd(), "\n");
	if (!context->busy_job)
		show_prompt(context);
}
