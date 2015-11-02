/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/15 17:57:28 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/22 23:56:53 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interpreter.h"

t_job		*last_run_job(t_context *context)
{
	t_job	*job;
	t_job	*last_job;
	int		job_id;
	t_list	*it;

	last_job = 0;
	job_id = 0;
	it = context->jobs;
	while (it)
	{
		job = (t_job *)it->content;
		if (job->job_id > job_id)
		{
			job_id = job->job_id;
			last_job = job;
		}
		it = it->next;
	}
	return (last_job);
}

void		probe_jobs(t_context *context)
{
	t_list	*it;
	t_job	*job;
	int		status;
	int		done;

	it = context->jobs;
	while (it)
	{
		job = (t_job *)it->content;
		status = wait_job(job, WNOHANG, &done);
		if (done)
		{
			context->last_status = WEXITSTATUS(status);
			show_finished_job(context, job, status);
			unwatch_job(context, job, 1);
		}
		it = it->next;
	}
}

void		put_job_in_foreground(t_context *context, t_job *job)
{
	int		status;

	set_fg_job(context, job);
	status = wait_job(job, WUNTRACED, 0);
	context->last_status = WEXITSTATUS(status);
	unwatch_job(context, job, !WIFSTOPPED(status));
	if (!WIFSTOPPED(status))
		set_fg_job(context, 0);
}
