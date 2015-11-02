/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 19:16:55 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/27 13:02:07 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interpreter.h"
#include "prompt.h"
#include "termcaps.h"

static void		control_jobs(t_context *context)
{
	if (context->do_susp && context->busy_job)
	{
		job_kill(context->busy_job, SIGTSTP);
		WRITE(tty_fd(), SHELL_ERROR_PREFIX);
		WRITE(tty_fd(), ": ");
		WRITE(tty_fd(), "suspended: ");
		ft_putendl_fd(context->busy_job->command_str, tty_fd());
		context->busy_job->stopped = 1;
		context->busy_job->job_id = ft_lstsize(context->jobs) + 1;
		watch_job(context, context->busy_job);
		context->do_susp = 0;
	}
	if (context->probe_jobs)
	{
		probe_jobs(context);
		context->probe_jobs = 0;
	}
}

static void		read_forever(t_context *context)
{
	char		*line;

	while (1337)
	{
		show_prompt(context);
		line = read_line(context, tty_fd());
		exec_line(context, line);
		control_jobs(context);
		history_add(context, line);
		free(line);
	}
}

int				main(void)
{
	t_context	*context;

	context = get_context();
	dispatch_signals();
	termcaps_init(context);
	read_forever(context);
	shell_exit(context, EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
