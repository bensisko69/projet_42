/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 16:46:29 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/23 00:18:20 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>

#include "interpreter.h"
#include "tools.h"

/*
** For each traversed node, find the job builder function corresponding to the
** type of the first token of that node
*/
void				job_init(t_job *job, t_ast *node)
{
	t_job_builder	builder;
	t_token			*token;

	if (node)
	{
		token = (t_token *)node->tokens->content;
		builder = (t_job_builder)ft_map_get(*get_job_init_map(),
											&token->type,
											token_type_hash);
		if (builder)
			builder(job, node);
	}
}

void				job_clear(t_job *job)
{
	if (job->stdin_fd != STDIN)
		close(job->stdin_fd);
	if (job->stdout_fd != STDOUT)
		close(job->stdout_fd);
	ft_lstdel(&job->processes, (t_deleter)free);
	ft_lstdel(&job->token_values, (t_deleter)free);
	free(job->command_str);
}

static int			job_status(t_context *context, t_job *job, int foreground)
{
	int				status;

	status = 1;
	if (foreground)
	{
		set_fg_job(context, job);
		status = wait_job(job, WUNTRACED, 0);
		if (WIFSIGNALED(status) && WTERMSIG(status) != SIGINT)
			shell_error(signal_name(WTERMSIG(status)), job->command_str);
		context->last_status = WEXITSTATUS(status);
		if (WIFSTOPPED(status))
			return (1);
		set_fg_job(context, 0);
		job_clear(job);
	}
	else
	{
		job_start_notify(context, job);
		watch_job(context, job);
	}
	if (!WIFEXITED(status))
		return (0);
	return (!WEXITSTATUS(status));
}

int					job_start(t_context *context, t_ast *node, int foreground)
{
	t_job			job;
	int				status;

	ft_bzero(&job, sizeof(t_job));
	job.stdout_fd = STDOUT;
	job.stdin_fd = STDIN;
	job_init(&job, node);
	if (job.stdin_fd == -1 || job.stdout_fd == -1)
	{
		job_clear(&job);
		return (1);
	}
	job.command_str = join_str_list(job.token_values, ' ');
	if (foreground && single_builtin(context, &job, &status))
	{
		job_clear(&job);
		return (status);
	}
	exec_job(context, &job);
	return (job_status(context, &job, foreground));
}

void				job_kill(t_job *job, int sig)
{
	t_list			*it;
	t_process		*process;

	it = job->processes;
	while (it)
	{
		process = (t_process *)it->content;
		kill(process->pid, sig);
		it = it->next;
	}
}
