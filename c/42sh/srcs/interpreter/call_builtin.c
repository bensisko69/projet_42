/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 18:52:16 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/27 18:34:23 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interpreter.h"

static void		dup_fds(t_job *job, int *in_backup, int *out_backup)
{
	if (job->stdin_fd != STDIN)
	{
		*in_backup = dup(STDIN);
		dup2(job->stdin_fd, STDIN);
		close(job->stdin_fd);
	}
	if (job->stdout_fd != STDOUT)
	{
		*out_backup = dup(STDOUT);
		dup2(job->stdout_fd, STDOUT);
		close(job->stdout_fd);
	}
}

static void		restore_standard_fds(t_job *job, int in_backup, int out_backup)
{
	if (job->stdin_fd != STDIN)
		dup2(in_backup, STDIN);
	if (job->stdout_fd != STDOUT)
		dup2(out_backup, STDOUT);
}

int				call_builtin(t_context *context, t_job *job, t_builtin builtin)
{
	t_process	*process;
	int			ret;
	int			stdin_backup;
	int			stdout_backup;

	stdin_backup = 0;
	stdout_backup = 0;
	dup_fds(job, &stdin_backup, &stdout_backup);
	process = (t_process *)job->processes->content;
	ret = builtin(context, process->args);
	restore_standard_fds(job, stdin_backup, stdout_backup);
	return (ret == BUILTIN_SUCCESS);
}

int				single_builtin(t_context *context, t_job *job, int *status)
{
	t_process	*process;
	t_builtin	builtin;

	if (ft_lstsize(job->processes) == 1)
	{
		process = (t_process *)job->processes->content;
		builtin = get_builtin(token_value(process->args, 1));
		if (builtin)
		{
			*status = call_builtin(context, job, builtin);
			context->last_status = (*status == BUILTIN_SUCCESS);
			return (1);
		}
	}
	return (0);
}
