/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fg.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 20:28:15 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/23 01:41:20 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "interpreter.h"
#include "termcaps.h"

int			b_fg(t_context *context, t_list *args)
{
	t_job	*job;

	UNUSED(args);
	job = last_run_job(context);
	if (!job)
		return (builtin_error(FG_BUILTIN, ERR_NO_CURRENT_JOB, 0));
	if (job->stopped)
	{
		job_kill(job, SIGCONT);
		job->stopped = 0;
	}
	WRITE(tty_fd(), "[");
	ft_putnbr_fd(job->job_id, tty_fd());
	WRITE(tty_fd(), "] ");
	if (job == last_run_job(context))
		WRITE(tty_fd(), "+ ");
	WRITE(tty_fd(), "continued \t");
	ft_putendl_fd(job->command_str, tty_fd());
	put_job_in_foreground(context, job);
	return (BUILTIN_SUCCESS);
}
