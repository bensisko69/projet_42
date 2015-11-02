/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watch_job.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 22:54:36 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/23 00:07:44 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interpreter.h"

void		watch_job(t_context *context, t_job *job)
{
	t_list	*job_list_link;

	job_list_link = ft_lstnew(job, sizeof(t_job));
	ft_lstappend(&context->jobs, job_list_link);
}

static int	compare_pointers(void *job1, size_t size1, void *job2, size_t size2)
{
	UNUSED(size1);
	UNUSED(size2);
	return (job1 == job2);
}

void		unwatch_job(t_context *context, t_job *job, int free_job)
{
	t_list	*job_list_link;

	job_list_link = ft_lstremove(&context->jobs, job, 0, compare_pointers);
	if (job_list_link)
	{
		if (free_job)
			job_clear(job);
		free(job);
		free(job_list_link);
	}
}
