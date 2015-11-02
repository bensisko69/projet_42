/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_job.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 20:05:33 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/19 20:56:40 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "interpreter.h"

static void	reset_fg_job(t_context *context)
{
	free(context->busy_job);
	context->busy_job = 0;
}

void		set_fg_job(t_context *context, t_job *job)
{
	t_job	*job_cpy;

	if (!job)
		return (reset_fg_job(context));
	job_cpy = (t_job *)malloc(sizeof(t_job));
	ft_memcpy(job_cpy, job, sizeof(t_job));
	free(context->busy_job);
	context->busy_job = job_cpy;
}
