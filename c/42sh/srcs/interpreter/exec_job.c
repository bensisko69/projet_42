/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_job.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 19:23:13 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/23 02:08:44 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interpreter.h"

static void	pipe_if(int condition, int fds[2], int *out_fd, int fallback_fd)
{
	if (condition)
	{
		if (pipe(fds) == -1)
			return (shell_error(ERR_PIPE, 0));
		*out_fd = fds[PIPE_WRITE_END];
	}
	else
		*out_fd = fallback_fd;
}

static void	fork_process(t_context *context, t_job *job, t_process *process)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		return (shell_error(ERR_FORK, 0));
	if (pid == 0)
		start_process(context, process);
	else
	{
		process->pid = pid;
		job->last_pid = pid;
	}
}

static void	close_job_fds(int in_fd, int out_fd, t_job *job)
{
	if (in_fd != job->stdin_fd)
		close(in_fd);
	if (out_fd != job->stdout_fd)
		close(out_fd);
}

void		exec_job(t_context *context, t_job *job)
{
	t_process	*process;
	t_list		*it;
	int			pipe_fds[2];
	int			in_fd;
	int			out_fd;

	out_fd = 0;
	in_fd = job->stdin_fd;
	it = job->processes;
	while (it)
	{
		process = (t_process *)it->content;
		pipe_if(it->next != 0, pipe_fds, &out_fd, job->stdout_fd);
		process->fd_in = in_fd;
		process->fd_out = out_fd;
		fork_process(context, job, process);
		close_job_fds(in_fd, out_fd, job);
		in_fd = pipe_fds[PIPE_READ_END];
		it = it->next;
	}
}
