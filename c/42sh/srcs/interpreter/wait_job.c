/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_job.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 15:08:58 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/23 02:09:00 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interpreter.h"

int				wait_job(t_job *job, int options, int *done_p)
{
	t_list		*it;
	t_process	*process;
	int			status;
	int			done;

	done = 0;
	it = job->processes;
	while (it)
	{
		process = (t_process *)it->content;
		done = waitpid(process->pid, &status, options);
		it = it->next;
	}
	if (done_p)
		*done_p = done;
	return (status);
}
